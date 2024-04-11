#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;
const int k_Sqrt_N = 400;

int n, m;

int a[k_N + 3];
int cnt[403][k_N + 3];
int add[403];

array<int, 30> lucky_numbers;
int is_lucky[10003];

inline int get_bucket_idx(int position){
    return ( (position - 1) / k_Sqrt_N );
}

inline int get_bucket_begin(int idx){
    return (1 + idx * k_Sqrt_N);
}

inline int get_bucket_end(int idx){
    return min(get_bucket_begin(idx + 1) - 1, n);
}

void update_bucket(int idx){
    int bucket_begin = get_bucket_begin(idx);
    int bucket_end = get_bucket_end(idx);
    for(int i = bucket_begin; i <= bucket_end; ++i){
        --cnt[idx][a[i]];
        a[i] += add[idx];
        ++cnt[idx][a[i]];
    }

    add[idx] = 0;
}

bool check_is_lucky(int number){
    while(number){
        if(number % 10 != 4 && number % 10 != 7)
            return false;
        number /= 10;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt_lucky_numbers = 0;
    for(int i = 1; i <= 10000; ++i){
        is_lucky[i] = check_is_lucky(i);
        if(is_lucky[i])
            lucky_numbers[cnt_lucky_numbers++] = i;
    }

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        cnt[get_bucket_idx(i)][a[i]]++;

    for(int query = 1; query <= m; ++query){
        string type;
        cin >> type;

        if(type == "count"){
            int l, r;
            cin >> l >> r;

            if(get_bucket_idx(l) == get_bucket_idx(r)){
                int answer = 0;

                update_bucket(get_bucket_idx(l));
                for(int i = l; i <= r; ++i)
                    answer += is_lucky[a[i]];

                cout << answer << "\n";
                continue;
            }

            int answer = 0;
            int l_bucket = get_bucket_idx(l), r_bucket = get_bucket_idx(r);
            
            update_bucket(l_bucket);
            for(int i = l; i <= get_bucket_end(l_bucket); ++i)
                answer += is_lucky[a[i]];


            update_bucket(r_bucket);
            for(int i = r; i >= get_bucket_begin(r_bucket); --i)
                answer += is_lucky[a[i]];

            for(int bucket = l_bucket + 1; bucket <= r_bucket - 1; ++bucket)
                for(int number: lucky_numbers)
                    if(number >= add[bucket])
                        answer += cnt[bucket][number - add[bucket]];

            cout << answer << "\n";
            continue;
        }
        
        assert(type == "add");

        int l, r, value;
        cin >> l >> r >> value;

        int l_bucket = get_bucket_idx(l), r_bucket = get_bucket_idx(r);
        if(l_bucket == r_bucket){

            for(int i = l; i <= r; ++i){
                cnt[l_bucket][a[i]]--;
                a[i] += value;
                cnt[l_bucket][a[i]]++;
            }
            continue;
        }

        for(int i = l; i <= get_bucket_end(l_bucket); ++i){
            cnt[l_bucket][a[i]]--;
            a[i] += value;
            cnt[l_bucket][a[i]]++;
        }

        for(int i = r; i >= get_bucket_begin(r_bucket); --i){
            cnt[r_bucket][a[i]]--;
            a[i] += value;
            cnt[r_bucket][a[i]]++;
        }

        for(int bucket = l_bucket + 1; bucket <= r_bucket - 1; ++bucket)
            add[bucket] += value;
    }
}