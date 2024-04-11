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
#define hp se.fi
#define dmg se.se
const ll MAX=300005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll x,y,a,b;
ll n,cnt1,cnt2,ans;
bool vis[MAX];
vector<int> v[MAX];
void dfsx(int pos){
	if(pos == y)return;
	if(vis[pos])return;
	vis[pos]=1;
	int sz = v[pos].size(); sz--;
	rep(i,0,sz){
		int nx = v[pos][i];
		dfsx(nx);
	}
}
void dfsy(int pos){
	if(pos == x)return;
	if(vis[pos])return;
	vis[pos]=1;
	int sz = v[pos].size(); sz--;
	rep(i,0,sz){
		int nx = v[pos][i];
		dfsy(nx);
	}
}
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y; ans=n*(n-1);
    rep(i,1,n-1){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	cnt1=n, cnt2=n;
	dfsx(x);
	rep(i,1,n)if(vis[i])cnt1--, vis[i]=0;
	dfsy(y);
	rep(i,1,n)if(vis[i])cnt2--;
	//cout<<cnt1<<" "<<cnt2<<endl;
	cout<<ans-cnt1*cnt2;
    return 0;
}