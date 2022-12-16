// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

int add(int x){ return x; }
template<typename... args> int add(int x, args... y){ return (x + add(y...)) % mod; }

ll n;

int sigma(function<int(int)> f){
    int ans = 0;
    for(int i = 0; 1ll * i * i <= n; i++)
	ans = add(ans, f(i));
    return ans;
}
int C2(ll n){
    ll A = n, B = n-1;
    if(n & 1)
	B/=2;
    else
	A/=2;
    return 1ll * (A % mod) * (B % mod) % mod;
}
int C3(ll n){
    ll A = n, B = n-1, C = n-2;
    if(n & 1)
	B/=2;
    else
	A/=2;
    if(A % 3 == 0)
	A/=3;
    else if(B % 3 == 0)
	B/=3;
    else
	C/=3;
    return 1ll * (A % mod) * (B % mod) % mod * (C % mod) % mod;
}

int _FOR2[maxn], _FOR4[maxn];

int FOR2(int c){
    return _FOR2[c-1];
}
int FOR4(int c){
    return _FOR4[c-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 1; i < maxn; i++)
	_FOR2[i] = ( 1ll * _FOR2[i-1] + 1ll * i * i ) % mod;
    for(int i = 1; i < maxn; i++)
	_FOR4[i] = ( 1ll * _FOR4[i-1] + 1ll * i * i % mod * i % mod * i ) % mod;
    cin >> n;    
    int ans = add(
		  1ll * C3(n+2) * 
		  sigma( [](int x){
			     int c = int(sqrt(n - 1ll * x * x)) + 1;
			     return c;
			 } ) % mod,
		  -1 * 
		  sigma( [](int x){
			     int c = int(sqrt(n - 1ll * x * x)) + 1;
			     return (1ll * c * C3(1ll * x * x) + 1ll * (FOR2(c) + c) * C2(1ll * x * x)) % mod;
			 } ),
		  -1 * 
		  sigma( [](int x){
			     int c = int(sqrt(n - 1ll * x * x)) + 1;
			     return (1ll * c * C3(1ll * x * x + 1) + 1ll * FOR2(c) * C2(1ll * x * x + 1)) % mod;
			 } ),
		  -1ll * ((n + 1)% mod) * 
		  sigma( [](int x){
			     int c = int(sqrt(n - 1ll * x * x)) + 1;
			     return (2ll * c * C2(1ll * x * x) + 1ll * x * x %mod * FOR2(c)) %mod; 
			 } ) % mod,
		  sigma( [](int x){
			     int c = int(sqrt(n - 1ll * x * x)) + 1;
			     return ( 2ll * C2(1ll * x * x) * (1ll * FOR2(c) + 1ll * x * x % mod * c % mod) + 1ll * x * x %mod * (1ll * FOR4(c) + 1ll * x * x %mod * FOR2(c) %mod) ) % mod;
			 } )
		  );
    for(int x = 1; 1ll * x * x <= n; x++)
	ans = add(ans, -add( C3(n+2), -C3(1ll * x * x + 1), -1ll * ((n+1) % mod) * C2(1ll * x * x) % mod, 1ll * (1ll * x * x) % mod * C2(1ll * x * x) % mod ));
    ans = 4ll * ans % mod;
    ans = add(ans, -3ll * C3(n+2) % mod);    
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;		   
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")