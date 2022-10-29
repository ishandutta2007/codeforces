#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

const ll M = 1e9+7;

ll pw(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1){ ret = ret * a % M; }
		b>>=1;
		a = a * a % M;
	}
	return ret;
}

void solve(){
	ll n, m, k, r, c; cin >> n >> m >> k >> r >> c;
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	if(x1 > x2)swap(x1,x2);
	if(y1 > y2)swap(y1,y2);
	ll ans = 1;
	ll sz1 = r*c, sz2 = sz1;
	if(x1+r-x2 > 0 && y1+c-y2 > 0) sz2-= (x1+r-x2)*(y1+c-y2);
	if(!sz2)ans*=(pw(k,sz1));
	else ans*=(pw(k,sz2));
	ans%=M;
	ans*=(pw(k,n*m-sz1-sz2));
	ans%=M;
	cout << ans << '\n';


}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}