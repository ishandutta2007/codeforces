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
//#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={0,0,-1,1,1,1,-1,-1};
const int dc[]={1,-1,0,0,1,-1,-1,1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int tc,r,c,nr,nc,mx,br,bc,cnt,a,b,d,mn,A,B;
vector<string> lis = {"Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right"};
map<string,int> tr;
vector<pii> v,tmp;
string s;
bool st;

inline bool ins(int r,int c){
	return r>0 && c>0 && r<9 && c<9;
}

inline bool cek(int a,int b,int _r=r,int _c=c){
	return a!=_r && b!=_c && a+b!=_r+_c && a-b!=_r-_c;
}

inline bool val(int a,int b,int _r=r,int _c=c){
	return ins(a,b) && cek(a,b,_r,_c);
}

int na,nb;
inline string ato(){
	a = na, b = nb;
	string ret = "Done";
	rep(i,0,7){
		na = a+dr[i], nb = b+dc[i];
		if(val(na,nb))ret = lis[i];
		// && (ret=="Done" || rand()%2)
	}
	if(ret!="Done"){
		d = tr[ret];
//		db(d);
//		out(a,b);
		na = a+dr[d], nb = b+dc[d];
//		out(na,nb);
	}
	return ret;
}

inline void king(){
//	s = ato();
//	cout<<s<<endl;
//	out(na,nb);
	cin>>s;
	if(s=="Done"){
		st = 1;
		return;
	}
	d = tr[s];
	tmp.clear();
	for(pii i:v){
		a = i.fi+dr[d], b = i.se+dc[d];
		if(val(a,b))tmp.pb({a,b});
	}
	v = tmp;
	return;
}

int po;
inline void find(){
	if(v.size()==0)exit(0);
	po = rand()%v.size();
	A = v[po].fi, B = v[po].se;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	rep(i,0,7)tr[lis[i]] = i;
	cin>>tc;
	rep(ntc,1,tc){
		v.clear();
		cout<<"4 4"<<endl;
		r = c = 4;
		rep(i,1,8)rep(j,1,8)if(i!=4 || j!=4)v.pb({i,j});
//		db(v.size());
		st = 0;
		rep(mv,1,8){
			king();
			if(st)break;
			mx = -1;
			rep(d,0,7){
				a = r+dr[d], b = c+dc[d];
				while(ins(a,b)){
					mn = v.size();
					rep(o,0,7){
						cnt = 0;
						for(pii i:v)cnt+= !val(i.fi+dr[o],i.se+dc[o],a,b);
						mn = min(mn,cnt);
					}
					if(mn>mx)mx = mn, br = a, bc = b;
					a+= dr[d], b+= dc[d];
				}
			}
			cout<<br<<" "<<bc<<endl;
			r = br, c = bc;
		}
		int cnt = 8;
		if(st)continue;
		find();
		while(1){
			king();
			if(st)break;
			++cnt;
			A+= dr[d], B+= dc[d];
			if(!val(A,B))find();
			if(A<=4){
				if(r!=A+1)r = A+1;
				else c = B;
			}
			else {
				if(r!=A-1)r = A-1;
				else c = B;
			}
			cout<<r<<" "<<c<<endl;
		}
	}
	return 0;
}