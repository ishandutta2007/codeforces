#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
const ll MAX=200010;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,x[MAX];
pll y[MAX];
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];sort(x+1,x+1+n);
	rep(i,1,n)cin>>y[i].fi,y[i].se=i;sort(y+1,y+1+n);
	rep(i,1,n)y[i].fi=x[n-i+1];
	rep(i,1,n)x[y[i].se]=y[i].fi;
	rep(i,1,n){
		if(i!=n)cout<<x[i]<<" ";
		else cout<<x[i]<<endl;
	}
    return 0;
}