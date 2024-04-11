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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],y[MAX],cnt,ans[10],it,j,k;
vector<int> h[MAX],v[MAX],d[MAX],b[MAX];

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>n;
    rep(i,1,n){
    	cin>>x[i]>>y[i];
    	h[x[i]].pb(y[i]);
    	v[y[i]].pb(x[i]);
    	d[x[i]+y[i]].pb(x[i]);
    	b[x[i]-y[i]+100000].pb(x[i]);
	}
	rep(i,1,300000)sort(all(h[i])), sort(all(v[i])), sort(all(d[i])), sort(all(b[i]));
	
	rep(i,1,n){
		cnt = 0;
		j = x[i], k = y[i];
		it = lower_bound(all(h[j]),k) - h[j].begin();
		if(it!=0)++cnt;
		if(it+1!=h[j].size())++cnt;
		
		j = y[i], k = x[i];
		it = lower_bound(all(v[j]),k) - v[j].begin();
		if(it!=0)++cnt;
		if(it+1!=v[j].size())++cnt;
		
		j = x[i]+y[i], k = x[i];
		it = lower_bound(all(d[j]),k) - d[j].begin();
		if(it!=0)++cnt;
		if(it+1!=d[j].size())++cnt;
		
		j = x[i]-y[i]+100000, k = x[i];
		it = lower_bound(all(b[j]),k) - b[j].begin();
		if(it!=0)++cnt;
		if(it+1!=b[j].size())++cnt;
		++ans[cnt];
	}
	rep(i,0,8)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}