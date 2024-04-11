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
const ll MOD = 998244353;
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

//int p[MAX],pn;
//bool prime[MAX];
//inline int initp(int N){
//	prime[0] = prime[1] = 1;
//	for(int i = 2; i*i<N; ++i)if(!prime[i]){
//		for(int j = i*i; j<N; j+=i)prime[j] = 1;
//	}
//	For(i,2,N)if(!prime[i])p[++pn] = i;
//	return pn;
//}

int n,q,op,x,a,b,y[MAX],mid;
set<ari(3)> mn;
set<ari(2)> rg;
vector<ari(2)> del;

inline void ins(int a,int b){
	if(a>b)return;
	rg.insert({a,b});
	if(a==1 || b==n)mn.insert({-(b-a+1),a,b});
	else mn.insert({-(b-a+2>>1),a,b});
}

inline void er(int a,int b){
	rg.erase({a,b});
	if(a==1 || b==n)mn.erase({-(b-a+1),a,b});
	else mn.erase({-(b-a+2>>1),a,b});
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	mn.insert({-n,1,n});
	rg.insert({1,n});
	auto it = rg.begin();
	
	while(q--){
		cin>>op>>x;
		if(op==1){
			a = (*mn.begin())[1], b = (*mn.begin())[2];
			er(a,b);
			if(a==b)y[x] = a;
			else if(a==1){
				y[x] = a;
				ins(2,b);
			}
			else if(b==n){
				y[x] = b;
				ins(a,b-1);
			}
			else {
				mid = a+b>>1;
				y[x] = mid;
				ins(a,mid-1), ins(mid+1,b);
			}
			cout<<y[x]<<endl;
		}
		else {
			x = y[x];
			a = b = -1;
			del.clear();
			it = rg.lower_bound({x,0});
			if(it!=rg.end() && (*it)[0]==x+1)del.pb(*it), b = (*it)[1];
			if(it!=rg.begin()){
				--it;
				if((*it)[1]==x-1)del.pb(*it), a = (*it)[0];
			}
			for(auto i:del)er(i[0],i[1]);
			if(a==-1)a = x;
			if(b==-1)b = x;
			ins(a,b);
		}
	}
	return 0;
}