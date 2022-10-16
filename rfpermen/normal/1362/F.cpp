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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = (1<<20)+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,a[MAX],b[MAX],bt,st,nw,p[MAX],ans[MAX],nx,hs[MAX],id,o,gg,cnt[MAX],ad[MAX];
pii tmp;
bool sta;
vector<pii> y[MAX];
set<piii> x[MAX];
queue<int> path;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>a[i]>>b[i];
    rap(k,20,0){
    	bt = (1<<k)-1;
    	rep(i,0,bt)ad[i] = cnt[i] = 0, p[i] = i;
    	rep(i,1,n){
    		a[i]%= (1<<k), b[i]%= (1<<k);
    		if(a[i]==b[i])ad[a[i]] = 1;
    		else {
    			p[par(a[i])] = par(b[i]);
    			++cnt[a[i]], ++cnt[b[i]];
			}
		}
		
		if(a[1]==b[1]){
			sta = 1;
			rep(i,1,n)if(a[i]!=b[i] || a[1]!=a[i]){
				sta = 0; break;
			}
			if(sta){
				cout<<k<<endl;
				rep(i,1,n)cout<<i*2-1<<' '<<i*2<<' '; cout<<endl;
				return 0;
			}
		}
		sta = 1;
		rep(i,0,bt)if((cnt[i]&1) || (ad[i] && !cnt[i]))sta = 0;
		if(!sta)continue;
		
		nw = par(a[1]);
		rep(i,1,n)if(nw!=par(a[i])||nw!=par(b[i])){
			nw = -1;
			break;
		}
		if(nw==-1)continue;
		
		rep(i,1,n){
    		if(a[i]==b[i])y[a[i]].pb({(i<<1)-1,i<<1});
    		else {
    			p[par(a[i])] = par(b[i]);
    			x[a[i]].insert({b[i],{(i<<1)-1,i<<1}});
    			x[b[i]].insert({a[i],{i<<1,(i<<1)-1}});
			}
			hs[(i<<1)-1] = a[i], hs[i<<1] = b[i];
		}
		
		cout<<k<<endl;
		o = id = st = (*x[a[1]].begin()).sf;
		
		while(id){
			nw = hs[id];
			do{
				nx = (*x[nw].begin()).fi;
				tmp = (*x[nw].begin()).se;
				path.push(tmp.fi), path.push(tmp.se);
				x[nw].erase({nx,tmp});
				x[nx].erase({nw,{tmp.se,tmp.fi}});
				nw = nx;
			}while(nw!=hs[id]);
			
			if(path.front()==o)path.pop();
			gg = ans[o];
			while(!path.empty())ans[o] = path.front(), o = path.front(), path.pop();
			ans[o] = gg;
			while(id && x[hs[id]].empty())o = id = ans[id];
		}
		sta = 0;
		while(st){
			cout<<st<<' ';
			nw = hs[st];
			while(sta&&!y[nw].empty())cout<<y[nw].back().fi<<' '<<y[nw].back().se<<' ', y[nw].pob();
			st = ans[st];
			sta^=1;
		}
		return 0;
	}
	return 0;
}