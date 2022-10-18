#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,k,a,b,x1,x2;
ll x[MAX][MAX],r[MAX][MAX],c[MAX][MAX],d1[MAX][MAX],d2[MAX][MAX],ans,res,df;
vector<pair<ll,pii>> v;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,-k,k){
    	a = -k+abs(i)+1, b = k-abs(i)-1;
    	rep(j,a,b)v.pb({k-abs(i)-abs(j),{i,j}});
	}
	
    rep(i,1,n)rep(j,1,m){
    	cin>>x[i][j];
    	r[i][j] = r[i-1][j]+x[i][j];
    	c[i][j] = c[i][j-1]+x[i][j];
    	d1[i][j] = d1[i-1][j-1]+x[i][j];
    	d2[i][j] = d2[i-1][j+1]+x[i][j];
	}
	a = n-k+1;
	b = m-k+1;
	ans = -1;
	rep(i,k,a){
		res = df = 0;
		for(pair<ll,pii> j:v)res+= j.fi*x[i+j.sf][k+j.ss];
		rep(j,1,k)df+= r[i+k-j][k+j]-r[i-k+j-1][k+j] - r[i+j-1][j]+r[i-j][j];
		rep(j,k,b){
			if(res>ans)ans = res, x1 = i, x2 = j;
			res+= df;
			df+= d2[i][j-k+1]-d2[i-k][j+1] + d1[i+k-1][j]-d1[i][j-k+1] - (r[i+k-1][j+1]-r[i-k][j+1]<<1);
			df+= d1[i][j+k+1]-d1[i-k][j+1] + d2[i+k-1][j+2]-d2[i][j+k+1];
		}
	}
	cout<<x1<<' '<<x2<<endl;
    return 0;
}