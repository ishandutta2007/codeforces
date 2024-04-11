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
const int dr[]={1,0,0,-1};
const int dc[]={0,-1,1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,cnt[MAX],cv[MAX],a,b,pos,val;
ll sm[MAX],tree[1<<19];
arll(3) x[MAX];
multiset<pii> s;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = sm[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc], tree[rc]);
	return;
}

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id]+= val;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = max(tree[lc], tree[rc]);
	return;
}

int que(int id,int le,int ri){
	if(x[le][0]>pos || tree[id]<pos)return 0;
	if(le==ri)return le;
	int mid = le+ri>>1;
	int res = que(lc,le,mid);
	if(res)return res;
	return que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>x[i][0]>>x[i][1];
		x[i][2] = i;
	}
	sort(x+1,x+1+n);
	rep(i,1,n)sm[i] = x[i][0] + x[i][1];
	build(1,1,n);
	auto it = s.begin();
	rep(i,1,m){
		cin>>pos>>val;
		a = que(1,1,n);
//		out(i, a);
		if(a){
			++cnt[a];
			sm[a]+= val;
			upd(1,1,n);
			while(s.size()){
				it = s.lower_bound({x[a][0], 0});
				if(it==s.end())break;
				if((*it).fi <= sm[a]){
					val = (*it).se;
					++cnt[a];
					sm[a]+= val;
					upd(1,1,n);
					s.erase(it);
				}
				else break;
			}
		}
		else {
			s.insert({pos, val});
		}
	}
	rep(i,1,n)cv[x[i][2]] = i, sm[i]-= x[i][0];
	rep(i,1,n)cout<<cnt[cv[i]]<<" "<<sm[cv[i]]<<endl;
	return 0;
}