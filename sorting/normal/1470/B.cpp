#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;

int big[N];

int compress(int x){
    int ret = 1;
    while(x != 1){
        int cnt = 0, p = big[x];
        while(x % p == 0){
            ++cnt;
            x /= p;
        }
        if(cnt & 1) ret *= p;
    }
    return ret;
}

void sieve(){
    big[1] = 1;
    for(int i = 2; i < N; ++i){
        if(!big[i]){
            big[i] = i;
            for(int j = 2 * i; j <= N - 1; j += i)
                big[j] = i;
        }
    }
}

int get_ans(int &n, vector<int> &a){
    sort(a.begin(), a.end());
    int cnt = 1, max_cnt = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i - 1]){
            ++cnt;
        }
        else{
            max_cnt = max(max_cnt, cnt);
            if(cnt % 2 == 0){
                for(int j = i - 1; j >= i - cnt; --j)
                    a[j] = 1;
            }
            cnt = 1;
        }
    }

    max_cnt = max(max_cnt, cnt);
    if(cnt % 2 == 0){
        for(int j = n - 1; j >= n - cnt; --j)
            a[j] = 1;
    }

    return max_cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    sieve();

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            a[i] = compress(a[i]);
            //cout << a[i] << " ";
        }
        //cout << endl;
        
        int ans[3]{};
        ans[0] = get_ans(n, a);
        ans[1] = get_ans(n, a);
        ans[2] = get_ans(n, a);


        int q;
        cin >> q;
        for(int i = 0; i < q; ++i){
            long long w;
            cin >> w;
            w = min(w, 2ll);
            cout << ans[w] << "\n";
        }
    }
}