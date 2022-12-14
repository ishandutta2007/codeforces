//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1e6 + 9;
ll fen1[Maxn],fen2[Maxn];
pair<ll,ll> sr[Maxn];
void update(int v,ll x,ll *fen){
	v++;
	for(v;v < Maxn;v += v & -v) fen[v] += x;
}
ll query(int v,ll * fen){
	ll res = 0;
	v++;
	for(v;v;v -= v & -v) res += fen[v];
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n;i++) scanf("%d",&sr[i].first),sr[i].second = i;
	sort(sr,sr+n);
	reverse(sr,sr+n);
	ll ans = 0;
	for(int i = 0 ; i < n;i++){
		ll id = sr[i].second;
		ans += query(id,fen2);
		ll x = query(id,fen1);
		update(id,x,fen2);
		update(id,1,fen1);
	}
	cout << ans << endl;
	return 0;
}