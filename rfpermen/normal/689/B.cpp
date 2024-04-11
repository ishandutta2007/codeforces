#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,x,vis[MAX];
vector<int> v[MAX];
queue<int> q;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	v[i].pb(x);
    	v[i].pb(i-1);
    	v[i].pb(i+1);
	}
	memset(vis,-1,sizeof vis);
	vis[0] = vis[1] = vis[n+1] = 0;
	q.push(1);
	while(!q.empty()){
		x = q.front(); q.pop();
		for(auto i:v[x]){
			if(vis[i]!=-1)continue;
			vis[i] = vis[x]+1;
			q.push(i);
		}
	}
	rep(i,1,n)cout<<vis[i]<<" ";
    return 0;
}