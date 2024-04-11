#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,m,a,b,d[MAX],dp[MAX],nw;
vector<int> v[MAX];
queue<int> q;

int f(int nw){
	if(dp[nw]!=-1)return dp[nw];
	int ret = d[nw];
	for(int i:v[nw]){
		if(d[i]>d[nw])ret = min(ret,f(i));
		else ret = min(ret,d[i]);
	}
	return dp[nw] = ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n){
    		v[i].clear();
    		d[i] = dp[i] = -1;
		}
		rep(i,1,m){
			cin>>a>>b;
			v[a].pb(b);
		}
		d[1] = 0;
		q.push(1);
		while(!q.empty()){
			nw = q.front();
			q.pop();
			for(int i:v[nw])if(d[i]==-1){
				d[i] = d[nw]+1;
				q.push(i);
			}
		}
		rep(i,1,n)cout<<f(i)<<' '; cout<<endl;
	}
    return 0;
}