#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

ll solve(ll curr, ll prev, ll m){
    // cout << "solve " << curr << " " << prev << " " << m << endl;
    m /= curr;
    prev /= curr;

    vector<ll> primes;
    for(ll i = 2; i * i <= prev; ++i){
        if(prev % i == 0){
            primes.push_back(i);
            while(prev % i == 0)
                prev /= i;
        }
    }
    if(prev != 1)
        primes.push_back(prev);

    ll ans = 0;
    for(int i = 0; i < (1 << (int)primes.size()); ++i){
        int cnt = __builtin_popcount(i);
        ll num = 1;
        for(int j = 0; j < (int)primes.size(); ++j)
            if(i >> j & 1)
                num *= primes[j];

        if(cnt % 2 == 0)
            ans += m / num;
        else
            ans -= m / num;
    }

    // cout << "ans " << ans << endl;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for(ll &x: a)
            cin >> x;

        bool ok = true;
        for(int i = 1; i < n; ++i){
            if(a[i - 1] % a[i] != 0){
                ok = false;
            }
        }

        if(!ok){
            cout << "0\n";
            continue;
        }

        ll ans = 1;

        for(int i = 1; i < n; ++i){
            if(a[i] == a[i - 1]){
                ans *= m / a[i];
                ans %= MOD;
                continue;
            }

            ans *= solve(a[i], a[i - 1], m);
            ans %= MOD; 
        }
        cout << ans << "\n";
    }
}