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

ll tc,n,ans,z[16],x,y,cnt[30],tmp,a,o;
vector<ll> v;
bool st;

void bf(ll nw,ll x){
	if(x==10000000000){
		v.pb(nw);
		return;
	}
	bf(nw,x*10);
	bf(nw+x,x*10);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bf(0,100);
//    for(int i:v)cout<<i<<endl;
//    return 0;
	rep(i,0,9)rep(j,0,9)++cnt[i+j];
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	ans = 0;
    	for(ll k:v){
    		mems(z,0);
    		x = k;
    		rep(i,0,11){
    			z[i] = x&1;
    			x/= 10;
			}
			x = k, y = n;
			st = 1;
			a = 0, o = 1;
			rep(i,0,11){
				if(x%10>y%10){
					a+= 9*o;
					if(!z[i+2]){
						st = 0;
						break;
					}
				}
				else a+= (y%10-x%10)*o;
				o*= 10;
				x/= 10, y/= 10;
			}
			if(!st)continue;
//			out(k,a);
			x = a;
			tmp = 1;
			rep(i,0,11){
				if(x%10==9 && z[i])tmp*= cnt[9];
				else tmp*= cnt[z[i+2]*10+x%10];
				x/= 10;
			}
			ans+= tmp;
		}
		cout<<ans-2<<endl;
	}
	return 0;
}