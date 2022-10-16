#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
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
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vector<ll>>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int dp[MAX],n,k,x,y;

int f(int nw){
	if(!nw)return 0;
	if(dp[nw]!=-1)return dp[nw];
	if(nw&1)return dp[nw] = !f(nw-1);
	unordered_set<int> s;
	s.insert(f(nw-1));
	s.insert(f(nw>>1));
	rep(i,0,1)if(!s.count(i))return dp[nw] = i;
	return dp[nw] = 2;
}


int g(int nw){
	if(!nw)return 0;
	if(dp[nw]!=-1)return dp[nw];
	if(nw&1)return dp[nw] = !g(nw-1);
	unordered_set<int> s;
	s.insert(g(nw-1));
	s.insert(0);
	rep(i,0,1)if(!s.count(i))return dp[nw] = i;
	return dp[nw] = 2;
}

int h(int nw){
	if(nw<100)return f(nw);
	if(nw&1)return 0;
	if(h(nw>>1)&1)return 2;
	return 1;
}

int main(){
//	cout<<fixed<<setprecision(5);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	mems(dp,-1);
	cin>>n>>k;
//	n = 0, k = 1;
	if(k%2==0){
		rep(i,1,n){
			cin>>x;
			if(x==2)y^= 2;
			else if(x==1 || x%2==0)y^= 1;
		}
	}
	else {
		rep(i,1,n){
			cin>>x;
			y^= h(x);
		}
//		rep(i,1,10)cout<<i<<" = "<<f(i)<<endl;
	}
	cout<<(y ? "Kevin" : "Nicky")<<endl;
	return 0;
}