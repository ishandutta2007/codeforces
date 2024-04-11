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
const int MAX = 1e2+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,k,val,len,mx;
map<int,vii> x,y,xv,yv;
map<int,int> xl,yl;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int xa,xb,ya,yb;
	cin>>n>>m>>k;
	while(k--){
		cin>>xa>>ya>>xb>>yb;
		if(xa==xb){
			if(ya>yb)swap(ya,yb);
			x[xa].pb({ya,yb});
		}
		else {
			if(xa>xb)swap(xa,xb);
			y[ya].pb({xa,xb});
		}
	}
	int ls = 0;
	for(auto i:x){
		if((i.fi-ls)%2==0){
			xl[ls+1] = m;
			xv[ls+1].pb({0, m});
			val^= m;
		}
		ls = i.fi;
		len = mx = 0;
		sort(all(i.se));
		for(auto j:i.se){
			if(j.fi>mx){
				len+= j.fi-mx;
				xv[i.fi].pb({mx, j.fi-mx});
			}
			mx = max(mx, j.se);
		}
		if(mx!=m){
			len+= m-mx;
			xv[i.fi].pb({mx, m-mx});
		}
		xl[i.fi] = len;
		val^= len;
	}
	if((n-ls)%2==0){
		xl[ls+1] = m;
		xv[ls+1].pb({0, m});
		val^= m;
	}
	
	ls = 0;
	for(auto i:y){
		if((i.fi-ls)%2==0){
			yl[ls+1] = n;
			yv[ls+1].pb({0, n});
			val^= n;
		}
		ls = i.fi;
		len = mx = 0;
		sort(all(i.se));
		for(auto j:i.se){
			if(j.fi>mx){
				len+= j.fi-mx;
				yv[i.fi].pb({mx, j.fi-mx});
			}
			mx = max(mx, j.se);
		}
		if(mx!=n){
			len+= n-mx;
			yv[i.fi].pb({mx, n-mx});
		}
		yl[i.fi] = len;
		val^= len;
	}
	if((m-ls)%2==0){
		yl[ls+1] = n;
		yv[ls+1].pb({0, n});
		val^= n;
	}
	
	if(val){
		cout<<"FIRST\n";
		for(auto i:xl){
			if((i.se^val)<i.se){
				i.se = i.se-(i.se^val);
				len = 0;
				for(auto j:xv[i.fi]){
					if(len+j.se>=i.se){
						cout<<i.fi<<" 0 "<<i.fi<<" "<<j.fi+(i.se-len)<<endl;
						return 0;
					}
					len+= j.se;
				}
			}
		}
		for(auto i:yl){
			if((i.se^val)<i.se){
				i.se = i.se-(i.se^val);
				len = 0;
				for(auto j:yv[i.fi]){
					if(len+j.se>=i.se){
						cout<<"0 "<<i.fi<<" "<<j.fi+(i.se-len)<<" "<<i.fi<<endl;
						return 0;
					}
					len+= j.se;
				}
			}
		}
	}
	else cout<<"SECOND\n";
	return 0;
}