#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC target("tune=native")
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
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(x,y,sizeof x)
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
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 6e13;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
//ll fc[MAX],pre[MAX];
//inline ll cb(int n,int k){
//	if(k>n)return 0;
//	return fc[n] * pre[k] % MOD * pre[n-k] % MOD;
//}
//inline void combin(int N){
//	fc[0] = 1;
//	For(i,1,N)fc[i] = fc[i-1]*i%MOD;
//	pre[N-1] = pw(fc[N-1],MOD-2);
//	rap(i,N-2,0)pre[i] = pre[i+1]*(i+1)%MOD;
//}

int n,m,k,x[MAX],le,ri,mid,res,a,b,z,rem;
pii y[MAX];
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,n)cin>>x[i];
	rep(i,1,m)cin>>y[i].fi, y[i].se = i;
	sort(x+1,x+1+n);
	sort(y+1,y+1+m);
	x[n+1] = y[m+1].fi = MOD;
	
	le = 0, ri = m, res = -1;
	while(le<=ri){
		mid = le+ri>>1;
		a = 1, b = m-mid+1;
		rem = n+mid;
		st = 1;
		rep(i,0,MAX){
			z = min(rem,k);
			rep(j,1,z){
				if(x[a]<=y[b].fi){
					if(x[a]<i){
						st = 0;
						break;
					}
					++a;
				}
				else {
					if(y[b].fi<i){
						st = 0;
						break;
					}
					++b;
				}
			}
			rem-= z;
			if(!st || !rem)break;
		}
		if(st)res = mid, le = mid+1;
		else ri = mid-1;
	}
	cout<<res<<endl;
	rep(i,m-res+1,m)cout<<y[i].se<<' '; cout<<endl;
	return 0;
}