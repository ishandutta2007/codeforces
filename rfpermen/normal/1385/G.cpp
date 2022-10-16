#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int tc,n,x[MAX],y[MAX],nx,nw,hit;
bool vis[MAX],vs[MAX],st[MAX],ava;
vector<int> v[MAX],ans,lp;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)v[i].clear(), vis[i] = vs[i] = st[i] = 0;
    	rep(i,1,n)cin>>x[i], v[x[i]].pb(i);
    	rep(i,1,n)cin>>y[i], v[y[i]].pb(i);
    	
    	ava = 1;
    	rep(i,1,n)if(v[i].size()!=2)ava = 0;
    	if(!ava){cout<<"-1\n"; continue;}
    	
    	ans.clear();
    	rep(i,1,n)if(!vis[i]){
    		lp.clear(), nw = i, hit = 0;
    		while(!vis[nw]){
    			vis[nw] = 1;
    			lp.pb(nw);
    			if(vs[x[nw]]){
    				st[nw] = vs[y[nw]] = 1, ++hit;
    				nw = nw==v[y[nw]][0] ? v[y[nw]][1] : v[y[nw]][0];
				}
				else vs[x[nw]] = 1, nw = nw==v[x[nw]][0] ? v[x[nw]][1] : v[x[nw]][0];
			}
			
//			hit = 0;
//			cout<<">> ";
//			for(int j:lp){
//				if(vs[x[j]])st[j] = vs[y[j]] = 1, ++hit, cout<<y[j]<<' ';
//				else vs[x[j]] = 1, cout<<x[j]<<' ';
//			}
//			cout<<endl;
//			db(lp.size());
//			db(hit);
			if(hit>lp.size()-hit){
				for(int j:lp)if(!st[j])ans.pb(j);
			}
			else {
				for(int j:lp)if(st[j])ans.pb(j);
			}
		}
		cout<<ans.size()<<endl;
		for(int i:ans)cout<<i<<' '; cout<<endl;
	}
	return 0;
}