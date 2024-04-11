#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=(n);i<=(N);++i)
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
const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll tc,n,a,b,c,x,y,le,ri,mid,ans,delta,o;
arll(3) res;
arll(4) z[MAX];
arll(8) nw,nx;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n){
    		cin>>a>>b>>c;
    		z[i] = {-a+b+c,a-b+c,a+b-c,a+b+c};
		}
		le = 0, ri = 3e18+1e9;
		while(le<=ri){
			mid = le+ri>>1;
			rep(j,0,3){
				nw[j*2] = z[1][j]-mid;
				nw[j*2+1] = z[1][j]+mid;
			}
			st = 1;
			rep(i,2,n){
				rep(j,0,3){
					nx[j*2] = z[i][j]-mid;
					nx[j*2+1] = z[i][j]+mid;
				}
				rep(j,0,3){
					a = max(nw[j*2],nx[j*2]), b = min(nw[j*2+1],nx[j*2+1]);
					if(a>b){
						st = 0;
						break;
					}
					nw[j*2] = a, nw[j*2+1] = b;
				}
				if(!st)break;
			}
			if(st){
				st = 0;
				a = nw[0], b = nw[2], c = nw[4];
				delta = max(0ll,nw[6] - (a+b+c));
				o = min(delta,nw[1]-a);
				a+= o;
				delta-= o;
				o = min(delta,nw[3]-b);
				b+= o;
				delta-= o;
				o = min(delta,nw[5]-c);
				c+= o;
				delta-= o;
				if(delta==0){
					rep(i,max(nw[0],a-2),min(nw[1],a+2)){
						rep(j,max(nw[2],b-2),min(nw[3],b+2)){
							rep(k,max(nw[4],c-2),min(nw[5],c+2)){
								if(i+j+k<nw[6] || i+j+k>nw[7] || ((i+j)&1) || ((i+k)&1) || ((k+j)&1))continue;
								res = {(j+k)/2,(i+k)/2,(i+j)/2};
								st = 1;
								break;
							}
							if(st)break;
						}
						if(st)break;
					}
				}
			}
			if(st)ans = mid, ri = mid-1;
			else le = mid+1;
		}
		rep(i,0,2)cout<<res[i]<<" "; cout<<endl;
	}
	return 0;
}