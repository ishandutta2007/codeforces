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
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,k,x[MAX],a,b,y[MAX],le,ri,mid,ans,ans2,sz;
vector<int> v[MAX];
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>x[i], y[i]=x[i];
	sort(y+1,y+1+n);
	while(k--){
		cin>>a>>b;
		v[a].pb(x[b]);
		v[b].pb(x[a]);
	}
	rep(i,1,n)sort(v[i].begin(),v[i].end());
	rep(i,1,n){
		le=1, ri=n;ans=0;
		while(le<=ri){
			mid=(le+ri)/2;
			if(y[mid]>=x[i])ri=mid-1;
			else le=mid+1, ans=mid;
		}
		sz=v[i].size();
		if(!sz){
			cout<<ans<<" "; continue;
		}
		le=0, ri=sz-1;ans2=0;
		while(le<=ri){
			mid=(le+ri)/2;
			if(v[i][mid]>=x[i])ri=mid-1;
			else le=mid+1, ans2=mid+1;
		}
		cout<<ans-ans2<<" ";
	}
    return 0;
}