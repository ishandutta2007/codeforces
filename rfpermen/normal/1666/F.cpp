#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
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
//#define lc (id<<1)
//#define rc ((id<<1)|1)
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
const int MAX = 5e3+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tc,n,a,x[MAX],ps[MAX],id,k,cnt;
ll fc[MAX],pre[MAX],dp[MAX][MAX],y[MAX],z[MAX],o[MAX],pr[MAX][MAX];
inline void combin(int n){
	fc[0] = 1;
	rep(i,1,n)fc[i] = fc[i-1]*i%MOD;
	pre[n] = pw(fc[n],MOD-2);
	rap(i,n-1,0)pre[i] = pre[i+1]*(i+1)%MOD;
}
inline ll cb(int n,int k){
	if(k>n || k<0)return 0;
	//Rumus permutasi
	return fc[n] * pre[n-k] % MOD;
}

// z = pembagi
//ll f(int nw,int rem){
//	if(rem==0){
//		return z[id]*y[nw]%MOD * fc[ps[id]-ps[nw]] % MOD;
//	}
//	ll &ret = dp[nw][rem];
//	if(ret!=-1)return ret;
//	ret = 0;
//	int slot = (k-rem-1) - (ps[nw]-(k-rem)), sum = 0;
//	slot = (k-rem)*2-1 - ps[nw];
//	rep(i,nw+1,id){
//		sum+= x[i]-1;
//		if(sum>slot)break;
//		ret+= fc[slot] * pre[(k-rem)*2-1-sum - ps[nw]]%MOD * pr[i]%MOD * f(i,rem-1) % MOD * y[nw] % MOD;
//		//konstan * pre[slot-sum] * dependent_i * dependent_i,rem * konstan
//		++sum;
//	}
//	return ret%= MOD;
//}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	combin(MAX-1);
	cin>>tc;
//	tc = 1;
	rep(ntc,1,tc){
		cin>>n;
//		n = 2000;
		mems(x,0);
		mems(y,0);
		rep(i,1,n){
			cin>>a;
//			a = i;
			++x[a];
		}
		id = 0;
		rap(i,n,1)if(x[i])y[++id] = x[i];
		if(y[1]>1 || y[2]>1){
			cout<<"0\n";
			continue;
		}
		if(n==2){
			cout<<"1\n";
			continue;
		}
		y[0] = z[0] = 1;
		rep(i,1,id){
			x[i] = y[i];
			ps[i] = ps[i-1]+x[i];
			y[i] = y[i-1]*fc[x[i]]%MOD;
			z[i] = pw(y[i],MOD-2);
			o[i] = pre[x[i]-1];
		}
		k = n/2;
		rep(nw,1,id)dp[nw][0] = z[id]*y[nw]%MOD*fc[ps[id]-ps[nw]]%MOD;
		int slot,sum,le,ri,mid;
		ll res;
		rep(rem,1,k-2){
			rep(i,3,id){
				if((k-rem)*2-ps[i]<0)pr[i][rem-1] = pr[i-1][rem-1];
				else pr[i][rem-1] = (pr[i-1][rem-1] + dp[i][rem-1]*(z[i-1]*o[i]%MOD)%MOD*pre[(k-rem)*2-ps[i]])%MOD;
			}
			rep(nw,2,id){
				slot = (k-rem)*2-1 - ps[nw];
				le = nw+1, ri = id;
				res = -1;
				while(le<=ri){
					mid = le+ri>>1;
					sum = ps[mid]-ps[nw]-1;
					if(sum<=slot)res = mid, le = mid+1;
					else ri = mid-1;
				}
				if(res==-1)dp[nw][rem] = 0; 
				else dp[nw][rem] = fc[slot]*y[nw]%MOD * (pr[res][rem-1]-pr[nw][rem-1]) % MOD;
//				cout<<dp[nw][rem]<<" ";
			}
//			cout<<endl;
		}
		cout<<(dp[2][k-2] + MOD)%MOD<<endl;
	}
	return 0;
}