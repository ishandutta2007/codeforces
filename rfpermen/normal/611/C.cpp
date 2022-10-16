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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define Size(n) ((int)(n).size())
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
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,m,y[MAX][MAX],z[MAX][MAX],a,b,c,d,q,ans;
char x[MAX][MAX];

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    asd(i,1,n)rep(j,1,m){
    	y[i][j] = (x[i][j]=='.' && x[i+1][j]=='.') + y[i-1][j] + y[i][j-1] - y[i-1][j-1];
	}
	rep(i,1,n)asd(j,1,m){
    	z[i][j] = (x[i][j]=='.' && x[i][j+1]=='.') + z[i-1][j] + z[i][j-1] - z[i-1][j-1];
	}
	cin>>q;
	while(q--){
		cin>>a>>b>>c>>d;
		--c;
		ans = y[c][d] - y[a-1][d] - y[c][b-1] + y[a-1][b-1];
		++c;
		--d;
		ans+= z[c][d] - z[a-1][d] - z[c][b-1] + z[a-1][b-1];
		++d;
		cout<<ans<<endl;
	}
    return 0;
}