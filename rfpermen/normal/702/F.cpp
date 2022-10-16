#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vlll vector<pll>
#define vvll vector<vll>
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
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,q,k,x[MAX],y[30][MAX],oof[30][MAX],val[30][MAX],mn[30][MAX],sm,tmp,z;
int sp[30][18][MAX],pos[30][MAX],cnt[30][MAX],ls,nw;
pii X[MAX];
stack<pll> s;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>X[i].se>>X[i].fi, X[i].se*= -1;
	revsort(X+1,X+1+n);
	rep(i,1,n)x[i] = -X[i].se;
	
	rep(bit,0,29){
		while(!s.empty())s.pop();
		z = MOD;
		ls = sm = 0;
		rap(i,n,1){
			if(x[i]<(1<<bit+1)){
				if(x[i]&(1<<bit)){
					tmp = x[i]-sm;
					while(s.size() && s.top().fi>=tmp)s.pop();
					if(s.empty())z = tmp;
					else sp[bit][0][i] = s.top().se;
					ls = i;
					val[bit][i] = tmp;
					s.push({tmp, i});
				}
				else {
					sm+= x[i];
					y[bit][i] = x[i];
					cnt[bit][i] = 1;
				}
			}
			oof[bit][i] = sm;
			pos[bit][i] = ls;
			mn[bit][i] = z+sm;
		}
		rep(i,1,n){
			y[bit][i]+= y[bit][i-1];
			cnt[bit][i]+= cnt[bit][i-1];
		}
		rep(i,1,17)rep(j,1,n)sp[bit][i][j] = sp[bit][i-1][sp[bit][i-1][j]];
	}
	
	cin>>q;
	int bit,le,ri,mid,res,ans;
	while(q--){
		cin>>k;
		ans = 0;
		nw = 1;
		while(k && nw<=n){
			bit = 31-__builtin_clz(k);
			if(k>=mn[bit][nw]){
				ls = nw;
				nw = pos[bit][nw];
				if(k<val[bit][nw]+oof[bit][ls]){
					rap(i,17,0)if(sp[bit][i][nw]){
						if(k<val[bit][sp[bit][i][nw]]+oof[bit][ls]){
							nw = sp[bit][i][nw];
						}
					}
					nw = sp[bit][0][nw];
				}
				k-= val[bit][nw]+oof[bit][ls];
				ans+= cnt[bit][nw]-cnt[bit][ls-1]+1;
				++nw;
			}
			else {
				le = nw, ri = n, res = 0;
				while(le<=ri){
					mid = le+ri>>1;
					if(k>=y[bit][mid]-y[bit][nw-1]){
						res = mid;
						le = mid+1;
					}
					else {
						ri = mid-1;
					}
				}
				if(!res || cnt[bit][res]==cnt[bit][nw-1])break;
				ans+= cnt[bit][res]-cnt[bit][nw-1];
				k-= y[bit][res]-y[bit][nw-1];
				nw = res+1;
			}
		}
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}