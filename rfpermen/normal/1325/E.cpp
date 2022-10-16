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
const ll MOD = 1000000009;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,x,ans,p[MAX],a,b;
pii vis[MAX];
queue<int> q;
queue<pii> qq;
bool st,db;
vector<int> v[MAX],pr;
set<int> poi,cyc;
set<pii> koi;

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
    rep(i,1,1000000)p[i] = i;
    rep(wkwk,1,n){
    	cin>>x;
    	pr.clear();
    	for(int i = 2; i*i<=x; ++i){
    		if(x%i)continue;
    		st = 0;
    		while(x%i==0)x/=i, st^=1;
    		if(st)pr.pb(i);
		}
		if(x!=1)pr.pb(x);
		if(pr.empty())return cout<<"1\n",0;
		
		if(pr.size()==1){
			if(poi.count(pr[0]))db = 1;
			poi.insert(pr[0]);
		}
		else {
			a = pr[0], b = pr[1];
			if(koi.count({a,b}))db = 1;
			koi.insert({a,b});
			
			if(par(a)==par(b))cyc.insert(a);
			
			v[a].pb(b);
			v[b].pb(a);
			p[par(a)] = par(b);
			
		}
	}
	if(db)return cout<<"2\n",0;
	
	for(auto i:poi)vis[i].fi = i, q.push(i);
	
	ans = 1e9;
	
	while(!q.empty()){
		a = q.front(); q.pop();
		for(auto i:v[a]){
			if(vis[i].fi){
				if(vis[i].fi!=vis[a].fi)ans = min(ans, vis[i].se + vis[a].se + 1);
				continue;
			}
			if(vis[a].se>=(ans>>1))continue;
			vis[i] = {vis[a].fi, vis[a].se+1};
			q.push(i);
		}
	}
	ans+= 2;
//	if(n==1038)cout<<ans<<endl;
	
	memset(vis,0,sizeof vis);
	for(auto o:cyc){
		if(ans==3)return cout<<"3\n",0;
		vis[o] = {o,0};
		for(auto i:v[o])vis[i] = {o,1}, qq.push({i,o});
		
		while(!qq.empty()){
			a = qq.front().fi, b = qq.front().se; qq.pop();
			
			for(auto i:v[a])if(i!=b){
				if(vis[i].fi==o){
					ans = min(ans, vis[i].se + vis[a].se + 1);
					continue;
				}
				if(vis[a].se>=(ans>>1))continue;
				
				vis[i] = {o, vis[a].se+1};
				qq.push({i,a});
			}
		}
	}
	
	cout<<(ans<1e6 ? ans : -1)<<endl;
	return 0;
}