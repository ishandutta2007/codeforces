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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,x[MAX],y[MAX],c[MAX],k[MAX],p[MAX],id,a,b,jaw;
plll e[MAX*MAX];
vector<pii> ans;
vector<int> res;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i], p[i] = i;
    rep(i,1,n)cin>>c[i];
    rep(i,1,n)cin>>k[i];
    rep(i,1,n)rep(j,i+1,n)e[++id] = {(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),{i,j}};
    sort(e+1,e+1+id);
	rep(i,1,id){
		a = par(e[i].sf), b = par(e[i].ss);
		if(a==b)continue;
		if(c[a]<=e[i].fi&&c[b]<=e[i].fi)continue;
		if(c[a]<c[b])p[b] = a;
		else p[a] = b;
		jaw+=e[i].fi;
		ans.pb(e[i].se);
	}
	rep(i,1,n)if(par(i)==i)res.pb(i), jaw+=c[i];
	cout<<jaw<<endl;
	cout<<res.size()<<endl;
	for(auto i:res)cout<<i<<' '; cout<<endl;
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}