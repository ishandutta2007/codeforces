#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1000000007;
ll n,m,k,R,C,a,b,c,d;
ll ksm(ll a,ll x){
	ll ret=1;
	for (;x;x>>=1,a=a*a % M) if (x&1) ret=ret*a % M;
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> R >> C;
	cin >> a >> b >> c >> d;
	ll free=n*m-R*C;
	if (a==c && b==d) free=n*m;
	ll ans=ksm(k,free);
	cout << ans << '\n';
	return 0;
}