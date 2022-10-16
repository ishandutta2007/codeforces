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

ll n,q,x[MAX],op,val;
int a,b;
arll(3) tree[1<<19],ret;

inline arll(3) merge(arll(3) le,arll(3) ri,int a,int b){
	ret = {le[0],ri[1],le[2]+ri[2] + le[1]*ri[0]};
	if(le[0]==a)ret[0]+= ri[0];
	if(ri[1]==b)ret[1]+= le[1];
	return ret;
}

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = {val,val,val};
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = merge(tree[lc],tree[rc],mid-le+1,ri-mid);
	return;
}

arll(3) que(int id,int le,int ri){
	if(le>b || ri<a)return {0,0,0};
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	return merge(que(lc,le,mid), que(rc,mid+1,ri), max(0,mid-max(le,a)+1), max(0,min(ri,b)-mid));
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    --n;
    rep(i,1,n){
    	val = x[i]<=x[i+1];
    	a = i;
    	upd(1,1,n);
	}
//	cout<<tree[1][2]<<endl;
	while(q--){
		cin>>op>>a>>b;
		if(op==1){
			x[a] = b;
			if(a!=n+1){
				val = x[a]<=x[a+1];
				upd(1,1,n);
			}
			if(a!=1){
				--a;
				val = x[a]<=x[a+1];
				upd(1,1,n);
			}
		}
		else {
			if(a==b)cout<<"1\n";
			else {
				--b;
				cout<<que(1,1,n)[2]+(b-a+2)<<endl;
			}
		}
	}
	return 0;
}