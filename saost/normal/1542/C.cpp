#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=1; i<=r; ++i)
#define REP(i,l,r) for(int i=1; i<r; ++i)
using namespace std;
const int N = 100005, MOD = 1e9 + 7;
long long t, n, x, odd, even, a, b, pr[N], power[N];

void Init() {
    for(int i=2; i<=1000; ++i) if (!pr[i]) {
        for(int j=i*i; j<=1000; j+=i) pr[j] = 1;
        for(int j=i; j<=1000; j*=i) power[j] = i;
    }
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    cin >> t;
    while (t--) {
        cin >> n;
        long long res = 0;
        for(int i=2; n>0; ++i) if (power[i]) {
            res += (n - n / power[i]) % MOD * i % MOD; res %= MOD;
            n /= power[i];
        }
        cout << res << '\n';
    }
}