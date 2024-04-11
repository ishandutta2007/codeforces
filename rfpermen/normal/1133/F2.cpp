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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
ll n,m,d,a,b,p[MAX],cnt;
vector<int> v[MAX];
vector<pii> ans;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>d;
    rep(i,1,m){
    	cin>>a>>b;
    	if(a>b)swap(a,b);
    	v[a].pb(b);
	}
	if(v[1].size()<d)return cout<<"NO\n",0;
	
	rep(i,1,n)p[i] = i;
	rep(i,2,n){
		for(int j:v[i]){
			a = par(i), b = par(j);
			if(a==b)continue;
			p[a] = b;
			++cnt;
		}
	}
	a = 1;
	for(int j:v[a]){
		b = par(j);
		if(a==b)continue;
		ans.pb({a,j});
		--d;
		p[b] = a;
		++cnt;
	}
	if(cnt!=n-1||d<0)return cout<<"NO\n",0;
	
	rep(i,1,n)p[i] = i;
	for(pii i:ans)p[i.se] = p[i.fi];
	for(int i:v[1]){
		if(!d)break;
		b = par(i);
		if(a==b)continue;
		ans.pb({1,i});
		--d;
		p[b] = 1;
	}
	rep(i,2,n){
		for(int j:v[i]){
			a = par(i), b = par(j);
			if(a==b)continue;
			ans.pb({i,j});
			p[a] = b;
		}
	}
	cout<<"YES\n";
	for(pii i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}