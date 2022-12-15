#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;
const long long sqrtN = 1007;
const long long MAX = 1e6 + 7;

struct n_pair{
    long long first, second;
    long long idx;
};

long long a[N];
n_pair q[N];
long long cnt[MAX];
long long sum = 0;

long long res[N];

bool cmp(n_pair lvalue, n_pair rvalue){
    if(lvalue.first / sqrtN != rvalue.first / sqrtN){
        return lvalue.first < rvalue.first;
    }

    return lvalue.second < rvalue.second;
}

void add(long long idx){
    long long e = a[idx];

    sum -= cnt[e] * cnt[e]  * e;
    cnt[e]++;
    sum += cnt[e] * cnt[e] * e;
}

void rem(long long idx){
    long long e = a[idx];

    sum -= cnt[e] * cnt[e]  * e;
    cnt[e]--;
    sum += cnt[e] * cnt[e] * e;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;

    cin >> n >> t;

    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(long long i = 1; i <= t; i++){
        cin >> q[i].first >> q[i].second;
        q[i].idx = i;
    }

    sort(q + 1, q + 1 + t, cmp);

    long long l = 1, r = 0;

    for(long long i = 1; i <= t; i++){
        for(long long j = r + 1; j <= q[i].second; j++){
            add(j);
        }
        for(long long j = l - 1; j >= q[i].first; j--){
            add(j);
        }

        for(long long j = q[i].second + 1; j <= r; j++){
            rem(j);
        }
        for(long long j = q[i].first - 1; j >= l; j--){
            rem(j);
        }

        l = q[i].first;
        r = q[i].second;

        res[q[i].idx] = sum;
    }

    for(long long i = 1; i <= t; i++){
        cout << res[i] << "\n";
    }

    return 0;
}