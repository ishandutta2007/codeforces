// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int fac[maxn], ifac[maxn];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b >>= 1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}
int C(int n, int k){
    if(n < k)
	return 0;
    return 1ll * fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] % mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
	ifac[i] = 1ll * (i+1) * ifac[i+1] % mod;
    
    int n, m, g;
    cin >> n >> m >> g;
    int ans = 0;
    if(m == 0)
	ans = (n & 1) != g;
    if(m == 1){
	if(n == 0)
	    ans = g == 1;
	else
	    ans = (n & 1) != g;
    }
    if(m > 0){
	for(int i = g; i <= n && i < n+m-1; i+=2){	
	    ans = (ans + C(n-i+m-1, m-1)) % mod;
	}
    }
    return cout << ans << endl, 0;
}