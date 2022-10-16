#include<bits/stdc++.h>
 
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
const ll MOD = 2010408371;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,ans,a,b,c,k,pos;
ll hs[MAX],x[MAX],key = 724729,y,z,res;
string s,t;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s>>t;
	n = s.size();
	m = t.size();
	a = 1, b = 0;
	For(i,1,n){
		if(s[i]!=s[0]){
			c = a;
			++b;
		}
		else {
			++a;
		}
	}
	hs[0] = 1;
	rep(i,1,m)x[i] = (x[i-1]*key + t[i-1])%MOD, hs[i] = hs[i-1]*key % MOD;
//	rep(i,1,m)cout<<x[i]<<endl;
	
	k = 1;
	rep(i,1,m){
		if(a*i > m)break;
		if(b){
			if(a*i == m)break;
			if((m-a*i)%b!=0)continue;
			k = (m-a*i)/b;
			pos = c*i + b*k;
			z = (x[pos] - x[pos-k]*hs[k])%MOD;
			if(z<0)z+= MOD;
		}
		y = x[i];
		if(y==z && i==k)continue;
//		db(k);
//		out(y, z);
//		db(i);
		pos = 0;
		st = 1;
		for(char o:s){
			if(o==s[0]){
				pos+= i;
				res = (x[pos] - x[pos-i]*hs[i])%MOD;
				if(res<0)res+= MOD;
				if(res!=y){
					st = 0;
					break;
				}
			}
			else {
				pos+= k;
				res = (x[pos] - x[pos-k]*hs[k])%MOD;
				if(res<0)res+= MOD;
				if(res!=z){
					st = 0;
					break;
				}
			}
		}
//		if(st)db(i);
		ans+= st;
	}
	cout<<ans<<endl;
	return 0;
}