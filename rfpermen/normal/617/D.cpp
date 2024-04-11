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
#define sf se.fi
#define ss se.se
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
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ari(2) x[5];
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	rep(i,1,3)cin>>x[i][0]>>x[i][1];
	st = 1;
	rep(i,2,3)if(x[i][0]!=x[1][0])st = 0;
	if(st)return cout<<"1\n",0;
	st = 1;
	rep(i,2,3)if(x[i][1]!=x[1][1])st = 0;
	if(st)return cout<<"1\n",0;
	
	sort(x+1,x+4);
	if(x[1][0]==x[2][0] && !(x[1][1]<x[3][1] && x[2][1]>x[3][1]))return cout<<"2\n",0;
	if(x[2][0]==x[3][0] && !(x[2][1]<x[1][1] && x[3][1]>x[1][1]))return cout<<"2\n",0;
	rep(i,1,3)swap(x[i][0],x[i][1]);
	sort(x+1,x+4);
	if(x[1][0]==x[2][0] && !(x[1][1]<x[3][1] && x[2][1]>x[3][1]))return cout<<"2\n",0;
	if(x[2][0]==x[3][0] && !(x[2][1]<x[1][1] && x[3][1]>x[1][1]))return cout<<"2\n",0;
	cout<<"3\n";
	return 0;
}