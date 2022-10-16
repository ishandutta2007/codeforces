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

int n,x[MAX],a,b,ans,z[MAX];
vector<int> v[MAX];

void dfs(int nw,int par){
	z[nw] = x[nw];
	for(int i:v[nw])if(i!=par){
		dfs(i,nw);
		z[nw]|= z[i];
	}
	return;
}

void f(int nw,int par,int mask){
	mask|= x[nw];
	if(mask==3)return;
	int a = 0, b = 0, tmp;
	for(int i:v[nw])if(i!=par){
		if(z[i]&1)++a;
		if(z[i]&2)++b;
	}
	for(int i:v[nw])if(i!=par){
		tmp = mask;
		if(a-(z[i]&1))tmp|= 1;
		if(b-((z[i]&2)>>1))tmp|= 2;
		if(z[i]<3&&tmp<3)++ans;
		f(i,nw,tmp);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dfs(1,0);
	f(1,0,0);
	cout<<ans<<endl;
    return 0;
}