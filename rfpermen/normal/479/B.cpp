#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
ll gcd(ll r,ll v){
	if(v==0)return r;
	return gcd(v,r%v);
}
ll a,n,k,x[105],m;
pair<int,int> ans[1005],mx,mn;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>k;
	rep(i,1,a)cin>>x[i];
	rep(i,1,k){
		mx.fi=0, mn.fi=1e9;
		rep(i,1,a){
			if(mx.fi<x[i])mx=mp(x[i],i);
			if(mn.fi>x[i])mn=mp(x[i],i);
		}
		//cout<<" lalala "<<mx.se<<" "<<mn.se<<endl;
		if(mx.fi<=mn.fi+1)break;
		x[mx.se]--, x[mn.se]++;
		m++;
		ans[m]= mp(mx.se,mn.se);
	}
	mx.fi=0, mn.fi=1e9;
	rep(i,1,a){
		//cout<<x[i]<<endl;
		if(mx.fi<x[i])mx=mp(x[i],i);
		if(mn.fi>x[i])mn=mp(x[i],i);
	}
	cout<<mx.fi-mn.fi<<" "<<m<<endl;
	rep(i,1,m)cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	return 0;
}