#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
int n,a1,a2,mx,idmx,nw;
pair<pii,int> x[300005];
int main(){
	cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>x[i].fi.fi>>x[i].fi.se;
		x[i].fi.se*=-1;
		x[i].se=i;
	}
	sort(x+1,x+1+n);
	a1=a2=-1;
	rep(i,1,n){
		nw=-x[i].fi.se;
		if(nw<=mx)a1=x[i].se, a2=idmx;
		else mx=nw, idmx=x[i].se;
	}
	cout<<a1<<" "<<a2<<endl;
	return 0;
}