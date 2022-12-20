#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10, mod = 998244353;

int fac[maxn], ifac[maxn], a[maxn];

int Pow(int a, int b){
    int ans = 1;
    for(;b ;b>>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] % mod;
    
    int n;
    cin >> n;    
    int cof = 1ll * fac[2*n] * Pow(1ll * fac[n] * fac[n] % mod, mod-2) % mod;
    for(int i = 0; i < 2*n; i++)
	cin >> a[i];
    sort(a, a + 2*n);
    int ans = 0;
    for(int i = 0; i < 2*n-1; i++)
	ans = (1ll * ans + 1ll * min(i+1, 2*n-i-1) * (a[i+1] - a[i])) % mod;
    ans = 1ll * ans * cof % mod;
    ans+= mod;
    ans%= mod;
    return cout << ans << endl, 0;
}