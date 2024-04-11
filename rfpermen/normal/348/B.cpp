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

ll n,a,b,ttl,x[MAX],kpk[MAX];
vector<int> tmp[MAX],v[MAX];

void flat(int nw,int par){
	for(int i:tmp[nw]){
		if(i==par)continue;
		v[nw].pb(i);
		flat(i,nw);
	}
	return;
}

inline void cek(ll a,ll b){
	if((double)a*b>1e18){
		cout<<ttl<<endl;
		exit(0);
	}
	return;
}

void dfs(int nw){
	kpk[nw] = 1;
	if(v[nw].empty())return;
	ll gcd;
	for(int i:v[nw]){
		dfs(i);
		gcd = __gcd(kpk[nw],kpk[i]);
		kpk[nw]/=gcd;
		cek(kpk[nw],kpk[i]);
		kpk[nw]*=kpk[i];
	}
	cek(kpk[nw],v[nw].size());
	ll mn = INF;
	for(int i:v[nw])mn = min(x[i]/kpk[nw]*kpk[nw],mn);
	x[nw] = mn*v[nw].size();
	kpk[nw]*=v[nw].size();
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], ttl+=x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	tmp[a].pb(b);
    	tmp[b].pb(a);
	}
	flat(1,0);
	dfs(1);
	cout<<ttl-x[1]<<endl;
    return 0;
}