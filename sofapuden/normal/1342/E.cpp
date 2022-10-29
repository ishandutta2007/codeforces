#include<bits/stdc++.h>

using namespace std ;
typedef long long ll;
const int mxN = 2e5+1000;
const ll M = 998244353;
ll fac[mxN];

ll pw(ll a, ll b) {
ll ret = 1;
while(b){
if(b&1){
ret=ret*a%M;
} 
a=a*a%M;
b>>=1;
} 
return ret;
} 

ll inv(ll x) {
return pw(x, M-2);
}
ll C(ll n, ll k) {
return fac[n] *inv(fac[n-k] *fac[k]%M) %M;
} 
int main() {
ll n, k; cin >> n >> k;

fac[0] = 1;
if (k > n-1){
cout << 0 << endl;
return 0;
}
for(int i = 1; i < n+5; ++i) {
fac[i] =fac[i-1]*i%M;
} 
ll ans = 0;
ll c = n-k;
for(int i = c; i >= 0; --i) {
if(i%2 == c%2){
ans = (ans+(pw(i, n) *C(c, i) %M)) %M;
} else{
ans = (ans - (pw(i, n) *C(c, i) %M)) %M;
ans = (ans+M) %M;
} 
} 
ans = ans*C(n, c) %M;
if(k) ans = ans*2%M;
cout << ans << endl;
}