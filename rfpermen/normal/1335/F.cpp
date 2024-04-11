#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int tc,n,m,hit,a,b,ans,bl,id;
pii dp[MAX],tmp;
char c;
vector<char> x[MAX];
vector<int> cl[MAX];
vector<pii> lis[MAX];
vector<bool> st[MAX];
map<pii,pii> hs;
//bool cht;
 
inline int cv(int aa,int bb){
	return (aa-1)*m+bb;
}
 
pii f(int aa,int bb){
	pii &ret = dp[cv(aa,bb)];
	if(ret.fi!=-1)return ret;
	if(cl[aa][bb]==-1)return ret = hs[{aa,bb}];
	
	if(x[aa][bb]=='U')--aa;
	else if(x[aa][bb]=='D')++aa;
	else if(x[aa][bb]=='L')--bb;
	else if(x[aa][bb]=='R')++bb;
	
	ret = f(aa,bb), --ret.se;
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m;
    	rep(i,1,n)while(x[i].size()<=m)x[i].pb(0), cl[i].pb(0), st[i].pb(0);
    	rep(i,1,n)rep(j,1,m)cin>>c, st[i][j] = (c=='0');
    	rep(i,1,n)rep(j,1,m)cin>>x[i][j], cl[i][j] = 0;
    	
//    	if(ntc==3&&n==1)cht = 1;
//    	if(ntc==90&&cht){
//    		cout<<n<<' '<<m<<endl;
//    		rep(i,1,n){
//    			rep(j,1,m)cout<<st[i][j]; cout<<endl;
//			}
//    		rep(i,1,n){
//    			rep(j,1,m)cout<<x[i][j]; cout<<endl;
//			}
//		}
    	
    	id = n*m;
    	rep(i,1,id)dp[i] = {-1,-1};
    	
    	ans = bl = id = 0;
    	hs.clear();
    	
    	rep(i,1,n)rep(j,1,m){
    		if(cl[i][j])continue;
    		++hit;
    		a = i, b = j;
    		while(!cl[a][b]){
    			cl[a][b] = hit;
    			if(x[a][b]=='U')--a;
    			else if(x[a][b]=='D')++a;
    			else if(x[a][b]=='L')--b;
    			else if(x[a][b]=='R')++b;
			}
			if(cl[a][b]==hit)++id;
			
			while(cl[a][b]==hit){
    			cl[a][b] = -1;
    			hs[{a,b}] = {id,lis[id].size()};
    			lis[id].pb({a,b});
    			
    			if(x[a][b]=='U')--a;
    			else if(x[a][b]=='D')++a;
    			else if(x[a][b]=='L')--b;
    			else if(x[a][b]=='R')++b;
			}
		}
		
		rep(i,1,n)rep(j,1,m){
			if(cl[i][j]==-1)continue;
			f(i,j);
			a = dp[cv(i,j)].fi, b = dp[cv(i,j)].se;
//			cout<<"<>> "<<a<<' '<<b<<endl;
			b = b%(int)lis[a].size() + lis[a].size();
//			db(b);
			if(b>=lis[a].size())b-= lis[a].size();
			
			tmp = lis[a][b];
			a = tmp.fi, b = tmp.se;
//			cout<<i<<' '<<j<<" >> "<<a<<' '<<b<<endl;
			
			if(!st[a][b])st[a][b] = st[i][j];
		}
		rep(i,1,id)lis[i].clear();
		
		rep(i,1,n)rep(j,1,m)if(cl[i][j]==-1)++ans, bl+= st[i][j];
		
		cout<<ans<<' '<<bl<<endl;
//		if(ntc==90&&cht){
//    		rep(i,1,n){
//    			rep(j,1,m)cout<<st[i][j]; cout<<endl;
//			}
//		}
	}
	return 0;
}