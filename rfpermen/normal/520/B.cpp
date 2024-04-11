#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=998244353;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,m,vis[20005];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n>=m)return cout<<n-m,0;
    rep(i,0,20000)vis[i]=1e9;
    vis[n] = 0;
    while(vis[m]==1e9){
    	rep(i,1,20000){
	    	if(vis[i]==-1)continue;
	    	vis[i-1] = min(vis[i-1],vis[i]+1);
	    	if(i*2>20000)continue;
	    	vis[i*2] = min(vis[i*2],vis[i]+1);
		}
	}
	cout<<vis[m];
    return 0;
}