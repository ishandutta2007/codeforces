#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,m,vis[MAX][MAX],k,a,b,na,nb;
queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(15);
    freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    memset(vis,-1,sizeof vis);
    while(k--){
    	cin>>a>>b;
    	q.push({a,b});
    	vis[a][b] = 0;
	}
	while(!q.empty()){
		a = q.front().fi, b = q.front().se; q.pop();
		rep(i,0,3){
			na = a+dr[i], nb = b+dc[i];
			if(na>0&&nb>0&&na<=n&&nb<=m){
				if(vis[na][nb]==-1){
					vis[na][nb] = vis[a][b]+1;
					q.push({na,nb});
				}
			}
		}
	}
	rep(i,1,n)rep(j,1,m)if(vis[i][j]>k)k = vis[i][j], a = i, b = j;
	cout<<a<<' '<<b<<endl;
	return 0;
}