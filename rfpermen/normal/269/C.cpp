#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,m,a,b,c[MAX],x[MAX],y[MAX],ans[MAX],nw;
stack<int> s;
vector<pair<int,pii>> v[MAX];

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>b>>c[i];
    	y[a]+= c[i], y[b]+= c[i];
    	ans[i] = -1;
    	v[a].pb({b,{i,0}});
    	v[b].pb({a,{i,1}});
	}
	s.push(1);
	while(!s.empty()){
		nw = s.top(), s.pop();
		if(nw==n)continue;
		for(pair<int,pii> i:v[nw])if(ans[i.sf]==-1){
			ans[i.sf] = i.ss;
			x[i.fi]+= c[i.sf];
			if(x[i.fi]==(y[i.fi]>>1))s.push(i.fi);
		}
	}
	rep(i,1,m)cout<<ans[i]<<endl;
    return 0;
}