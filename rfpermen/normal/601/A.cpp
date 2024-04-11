#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 4e2+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,m,a,b,vis[MAX][MAX],uis[MAX][3],nx,ans;
bool vv[MAX][MAX],st,z[MAX];
vector<int> v[MAX],u[MAX],tmp[MAX];
queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b;
    	vv[a][b] = vv[b][a] = 1;
	}
	rep(i,1,n)rep(j,1,n){
		if(i==j)continue;
		if(vv[i][j])v[i].pb(j);
		else u[i].pb(j);
	}
	for(auto i:v[1])for(auto j:u[1]){
		if(i==j&&i!=n)continue;
		st = 1;
	}
	if(!st)return cout<<"-1\n",0;
	memset(vis,-1,sizeof vis);
	vis[1][0] = 0;
	q.push({1,0});
	while(!q.empty()){
		a = q.front().fi, b = q.front().se; q.pop();
		for(auto i:v[a]){
			if(vis[i][b]!=-1){
				nx = b+vis[a][b]-vis[i][b]+1;
				if(nx>2)continue;
				if(vis[i][nx]!=-1)continue;
				vis[i][nx] = vis[a][b]+1;
				q.push({i,nx});
			}
			else {
				vis[i][b] = vis[a][b]+1;
				q.push({i,b});
			}
		}
	}
	if(vis[n][0]==-1)return cout<<"-1\n",0;
	memset(z,0,sizeof z);
	z[n] = 1;
	q.push({n,0});
	while(!q.empty()){
		a = q.front().fi; q.pop();
		for(auto i:v[a]){
			if(vis[i][0]==vis[a][0]-1){
				tmp[i].pb(a);
				if(!z[i])z[i] = 1, q.push({i,0});
			}
		}
	}
	rep(i,1,n)v[i] = tmp[i], tmp[i].clear();
	
	memset(uis,-1,sizeof uis);
	uis[1][0] = 0;
	q.push({1,0});
	while(!q.empty()){
		a = q.front().fi, b = q.front().se; q.pop();
		for(auto i:u[a]){
			if(uis[i][b]!=-1){
				nx = b+uis[a][b]-uis[i][b]+1;
				if(nx>2)continue;
				if(uis[i][nx]!=-1)continue;
				uis[i][nx] = uis[a][b]+1;
				q.push({i,nx});
			}
			else {
				uis[i][b] = uis[a][b]+1;
				q.push({i,b});
			}
		}
	}
	if(uis[n][0]==-1)return cout<<"-1\n",0;
	memset(z,0,sizeof z);
	z[n] = 1;
	q.push({n,0});
	while(!q.empty()){
		a = q.front().fi; q.pop();
		for(auto i:u[a]){
			if(uis[i][0]==uis[a][0]-1){
				tmp[i].pb(a);
				if(!z[i])z[i] = 1, q.push({i,0});
			}
		}
	}
	rep(i,1,n)u[i] = tmp[i], tmp[i].clear();
	
	ans = 1e9;
	rep(i,0,2)rep(j,0,2){
		if((i==0&&j==0)||vis[n][i]==-1||uis[n][j]==-1)continue;
		ans = min(ans,max(vis[n][i],uis[n][j]));
	}
	
	memset(vis,-1,sizeof vis);
	q.push({1,1});
	vis[1][1] = 0;
	while(!q.empty()){
		a = q.front().fi, b = q.front().se; q.pop();
		if(a==n&&b==n)break;
		if(b==n){
			for(auto i:v[a]){
				if(vis[i][b]!=-1)continue;
				vis[i][b] = vis[a][b]+1;
				q.push({i,b});
			}
		}
		else if(a==n){
			for(auto i:u[b]){
				if(vis[a][i]!=-1)continue;
				vis[a][i] = vis[a][b]+1;
				q.push({a,i});
			}
		}
		else {
			for(auto i:v[a])for(auto j:u[b]){
				if(i==j&&i!=n)continue;
				if(vis[i][j]!=-1)continue;
				vis[i][j] = vis[a][b]+1;
				q.push({i,j});
			}
		}
	}
	if(vis[n][n]!=-1)ans = min(ans,vis[n][n]);
	cout<<ans<<endl;
	return 0;
}