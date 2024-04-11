#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,a,b,nx,nc,c,vis[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> v[MAX];
set<int> s;
map<int,int> x[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	v[b].pb({a,c});
	}
	rep(o,1,n){
		cin>>a;
		s.clear();
		while(a--)cin>>b, s.insert(-b);
		b = 2e9;
		for(int i:s){
			i = -i;
			if(b!=i+1)c = i+1;
			b = i;
			x[o][i] = c;
		}
	}
	x[n].clear();
	rep(i,1,n)vis[i] = 2e9;
	vis[1] = x[1][0];
	pq.push({x[1][0],1});
	while(!pq.empty()){
		a = pq.top().se, c = pq.top().fi; pq.pop();
		if(vis[a]<c)continue;
		for(auto i:v[a]){
			nx = i.fi, nc = c+i.se;
			if(x[nx].count(nc))nc = x[nx][nc];
			if(vis[nx]<=nc)continue;
			vis[nx] = nc;
			pq.push({nc,nx});
		}
	}
	cout<<(vis[n]!=2e9 ? vis[n] : -1)<<endl;
    return 0;
}