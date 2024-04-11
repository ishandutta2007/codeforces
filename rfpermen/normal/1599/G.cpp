#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
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
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<ll,x>
//#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,k,id;
set<ari(2)> s;
ari(2) x[MAX],y;

inline ll cross(ari(2) a,ari(2) b, ari(2) c){
	return (a[0]-c[0])*(b[1]-c[1]) - (a[1]-c[1])*(b[0]-c[0]);
}

inline bool find(int a,int b){
	id = -1;
	For(i,0,n)if(i!=a && i!=b){
		if(cross(x[a],x[i],x[b])!=0){
			if(id!=-1)return false;
			id = i;
		}
	}
	return true;
}

inline double dist(int a,int b){
	if(a<0 || b<0)return 0.;
	return hypot(x[a][0]-x[b][0], x[a][1]-x[b][1]);
}

int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	rep(i,1,n){
		cin>>x[i][0]>>x[i][1];
		s.insert(x[i]);	
	}
	y = x[k];
	n = 0;
	for(auto i:s)x[n++] = i;
	if(!find(0,1)){
		if(!find(0,2)){
			find(1,2);
		}
	}
	swap(x[id],x[n-1]);
	sort(x,x+n-1);
	For(i,0,n)if(x[i]==y)k = i;
	if(k==n-1){
		cout<<min(dist(0,k), dist(n-2,k)) + dist(0,n-2)<<endl;
		return 0;
	}
//	cout<<"___\n";
//	For(i,0,n){
//		cout<<x[i][0]<<" "<<x[i][1]<<endl;
//	}
	double ans = INF,a,b,c,d,e;
	ans = min(ans, dist(k,0) + dist(0,n-1) + dist(n-1,k+1) + dist(k+1,n-2));
	For(i,0,n-1){
		a = dist(k,0);
		b = dist(0,i);
		c = dist(i,n-1);
		d = dist(n-1,max(i+1,k+1));
		e = dist(max(i+1,k+1),n-2);
		if(i==n-2)ans = min(ans, a+b+c);
		else ans = min(ans, a+b+c+d+e);
	}
	ans = min(ans, dist(k,n-2) + dist(n-2,n-1) + dist(n-1,k-1) + dist(k-1,0));
	rap(i,n-2,0){
		a = dist(k,n-2);
		b = dist(n-2,i);
		c = dist(i,n-1);
		d = dist(n-1,min(k-1,i-1));
		e = dist(min(k-1,i-1),0);
		if(i==0)ans = min(ans, a+b+c);
		else ans = min(ans, a+b+c+d+e);
	}
	cout<<ans<<endl;
	return 0;
}