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
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,k,x[5][MAX];
vector<ari(3)> ans;

inline void mv(int a,int b,int c,int d){
	swap(a,c), swap(b,d);
	if(x[a][b] && !x[c][d]){
		swap(x[a][b],x[c][d]);
		ans.pb({x[c][d],c,d});
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	cin>>n>>k;
	rep(i,1,4)rep(j,1,n)cin>>x[i][j];
	int hit = 0;
	while(k){
//		cout<<"_________\n";
//		rep(i,1,4){
//			rep(j,1,n)cout<<x[i][j]<<" ";
//			cout<<endl;
//		}
		rep(i,1,n){
			if(x[2][i] && x[1][i]==x[2][i]){
				--k;
				ans.pb({x[2][i],1,i});
				x[2][i] = 0;
			}
			if(x[3][i] && x[4][i]==x[3][i]){
				--k;
				ans.pb({x[3][i],4,i});
				x[3][i] = 0;
			}
		}
		if(k==n*2)return cout<<"-1\n",0;
		For(i,1,n)mv(2,i,2,i+1);
		mv(2,n,3,n);
		rap(i,n,2)mv(3,i,3,i-1);
		if(rand()%3==0)mv(3,1,2,1);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
	return 0;
}