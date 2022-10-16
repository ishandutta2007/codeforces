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
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,x[MAX],y[MAX],sm[MAX],ans,a,b;
vector<int> v[MAX],tmp[MAX];

void tf(int nw,int par){
	for(auto i:tmp[nw]){
		if(i==par)continue;
		v[nw].pb(i);
		tf(i,nw);
	}
	return;
}

void f(int nw,ll at){
	x[nw] = __gcd(x[nw],at);
	sm[nw] = x[nw];
	for(auto i:v[nw]){
		if(x[i]!=__gcd(x[nw],x[i]))f(i,x[nw]);
		sm[nw]+=sm[i];
	}
	sm[nw]%=MOD;
	return;
}

void dfs(int nw){
	for(auto i:v[nw])dfs(i);
	f(nw,0);
	ans+=sm[nw];
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
    	tmp[a].pb(b);
    	tmp[b].pb(a);
	}
	tf(1,0);
	dfs(1);
	cout<<ans%MOD<<endl;
    return 0;
}