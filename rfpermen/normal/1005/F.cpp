#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,k,vis[MAX],nw;
pii e[MAX];
vector<pii> tmp[MAX];
vector<int> v[MAX];
vector<string> ans;
string s;
queue<int> q;
bool st[MAX];

void bf(int nw){
	if(!k)return;
	if(nw>n){
		--k;
		s = "";
		rep(i,1,m)s.pb('0'+st[i]);
		ans.pb(s);
		return;
	}
	for(int i:v[nw]){
		st[i] = true;
		bf(nw+1);
		st[i] = false;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,m){
    	cin>>e[i].fi>>e[i].se;
    	tmp[e[i].fi].pb({e[i].se,i});
    	tmp[e[i].se].pb({e[i].fi,i});
	}
	memset(vis,-1,sizeof vis);
	q.push(1);
	vis[1] = 0;
	while(!q.empty()){
		nw = q.front(); q.pop();
		for(pii i:tmp[nw])if(vis[i.fi]==-1){
			vis[i.fi] = vis[nw]+1;
			q.push(i.fi);
		}
	}
	rep(i,2,n)for(pii j:tmp[i])if(vis[j.fi]<vis[i])v[i].pb(j.se);
	bf(2);
	cout<<ans.size()<<endl;
	for(string i:ans)cout<<i<<endl;
    return 0;
}