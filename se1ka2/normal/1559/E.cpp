#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

struct PrimeDecomposition
{
    int n;
    vector<bool> p;
    vector<int> prime;
    vector<int> d;
    
    PrimeDecomposition(int n) : n(n){
        p.resize(n + 1);
        d.resize(n + 1);
        d[1] = 1;
        for(int i = 2; i <= n; i++){
            if(!p[i]){
                prime.push_back(i);
                for(int j = i; j <= n; j += i){
                    if(!p[j]) d[j] = i;
                    p[j] = true;
                }
            }
        }
    }
    
    vector<int> decomposition(int x){
        vector<int> res;
        while(x > 1){
            res.push_back(d[x]);
            x /= d[x];
        }
        return res;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int l[52], r[52];
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    PrimeDecomposition pd(m);
    ll ans = 0;
    for(int t = 1; t <= m; t++){
        vector<int> v = pd.decomposition(t);
        bool f = true;
        for(int i = 0; i < (int)v.size() - 1; i++){
            if(v[i] == v[i + 1]) f = false;
        }
        if(!f) continue;
        int a[52], b[52];
        for(int i = 0; i < n; i++){
            a[i] = (l[i] - 1) / t + 1;
            b[i] = r[i] / t;
        }
        int k = m / t;
        for(int i = 0; i < n; i++){
            k -= a[i];
            b[i] -= a[i];
            if(b[i] < 0) f = false;
        }
        if(!f || k < 0) continue;
        ll dp[100005], s[100005];
        s[0] = 0;
        for(int i = 1; i <= k + 1; i++) s[i] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= k; j++) dp[j] = (s[j + 1] + MOD - s[max(0, j - b[i])]) % MOD;
            for(int j = 1; j <= k + 1; j++) s[j] = (s[j - 1] + dp[j - 1]) % MOD;
        }
        if((int)v.size() % 2) ans = (ans + MOD - s[k + 1]) % MOD;
        else ans = (ans + s[k + 1]) % MOD;
    }
    cout << ans << endl;
}