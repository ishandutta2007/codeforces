#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,m[55],x[55][55],mn,a,b;
vector<piiii> ans;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>m[i];
    rep(i,1,n)rep(j,1,m[i])cin>>x[i][j];
    rep(i,1,n)rep(j,1,m[i]){
    	mn = MOD;
    	rep(k,j+1,m[i])if(x[i][k]<mn)mn = x[i][k], a = i, b = k;
    	rep(o,i+1,n)rep(k,1,m[o])if(x[o][k]<mn)mn = x[o][k], a = o, b = k;
    	if(x[i][j]>mn)swap(x[i][j],x[a][b]), ans.pb({{i,j},{a,b}});
	}
	cout<<ans.size()<<endl;
	for(piiii i:ans)cout<<i.ff<<' '<<i.fs<<' '<<i.sf<<' '<<i.ss<<endl;
//	cout<<"______\n";
//	rep(i,1,n){
//		rep(j,1,m[i])cout<<x[i][j]<<' '; cout<<endl;
//	}
    return 0;
}