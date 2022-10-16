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
const int MAX = 4e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll fc[MAX+5],pre[MAX+5];
inline ll cb(int n,int k){
	if(k>n)return 0;
	return fc[n] * pre[k] % MOD * pre[n-k] % MOD;
	return fc[n] * pw(fc[k],MOD-2) % MOD * pw(fc[n-k],MOD-2) % MOD;
}
inline void combin(int N){
	fc[0] = 1;
	rep(i,1,N)fc[i] = fc[i-1]*i%MOD;
	pre[N] = pw(fc[N],MOD-2);
	rap(i,N-1,0)pre[i] = pre[i+1]*(i+1)%MOD;
}

ll f,w,h,x[MAX],ttl,ans;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	combin(MAX);
	cin>>f>>w>>h;
	if(!f)return cout<<(w>h)<<endl,0;
	if(!w)return cout<<"1\n",0;
	rep(i,1,f)x[i] = cb(f-1,i-1);
	rep(i,1,w)ttl+= (x[i-1] + 2*x[i] + x[i+1])*cb(w-1,i-1)%MOD;
	rep(i,1,w){
		if(i*(h+1)>w)break;
		ans+= (x[i-1] + 2*x[i] + x[i+1])*cb(w-1-h*i,i-1)%MOD;
	}
	ans%= MOD, ttl%=MOD;
	cout<<ans*pw(ttl,MOD-2)%MOD<<endl;
	return 0;
}