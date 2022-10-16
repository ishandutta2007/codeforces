#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define asd(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
const int MAX = 3e2+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,k,y[MAX],a,b,st[MAX][MAX],z;
bool x[MAX];

inline void f(int a,int b,int val){
	if(a>b)swap(a,b);
	if(st[a][b] || !m)return;
	st[a][b] = val;
	if(val==1)--m;
	return;
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	z = n-k;
//	cout<<">> "<<n*(n-1)/2-1-(n-2-z)<<endl;
	if(k==n || m>n*(n-1)/2-1-(n-2-z))return cout<<"-1\n",0;
	rep(i,1,k){
		cin>>y[i];
		x[y[i]] = 1;
	}
	a = y[1], b = y[2];
	if(a>b)swap(a,b);
	rep(i,1,n)if(!x[i]){
		f(b,i,1);
		rep(j,1,n)if(j!=a && j!=b)f(a,j,1);
		rep(j,1,n)if(j!=a && j!=b){
			if(x[j])f(b,j,2);
			else f(b,j,1);
		}
		break;
	}
	rep(i,1,n)rep(j,i+1,n)if(i!=a || j!=b)f(i,j,1);
	if(m!=0)return 1;
	rep(i,1,n)rep(j,i+1,n)if(st[i][j]==1)cout<<i<<' '<<j<<endl;
	return 0;
}