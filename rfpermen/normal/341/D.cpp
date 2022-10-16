#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,q,ty,a,b,c,d;
ll bit[4][MAX][MAX],val,ret;

inline void upd(int id,int i,int j,ll val){
	for(;i<=n;i+=i&-i)
		for(int k = j;k<=n;k+=k&-k)bit[id][i][k]^= val;
	return;
}
inline void update(int a,int b,int c,int d,ll val){
	upd(((a&1)<<1)|(b&1),a,b,val),
	upd(((a&1)<<1)|(d&1),a,d,val),
	upd(((c&1)<<1)|(b&1),c,b,val),
	upd(((c&1)<<1)|(d&1),c,d,val);
	return;
}

inline ll que(int id,int i,int j){
	ll ret = 0;
	for(;i>0;i^=i&-i)
		for(int k = j;k>0;k^=k&-k)ret^= bit[id][i][k];
	return ret;
}
inline ll query(int a,int b,int c,int d){
	return
	que(((a&1)<<1)|(b&1),a,b)^
	que(((a&1)<<1)|(d&1),a,d)^
	que(((c&1)<<1)|(b&1),c,b)^
	que(((c&1)<<1)|(d&1),c,d);
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    while(q--){
    	cin>>ty>>a>>b>>c>>d;
    	if(ty==1)cout<<query(a-1,b-1,c,d)<<endl;
		else cin>>val, update(a,b,c+1,d+1,val);
	}
	return 0;
}