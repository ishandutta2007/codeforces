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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}

int n,q,a,b,st[MAX],en[MAX],cv[MAX],id,sp[17][MAX],dep[MAX];
vi v[MAX];
ari(4) tree[1<<18],ret;

inline ari(4) merge(ari(4) le,ari(4) ri){
	if(le[0]<ri[0]){
		ret[0] = le[0];
		if(le[1]<ri[0])ret[1] = le[1];
		else ret[1] = ri[0];
	}
	else {
		ret[0] = ri[0];
		if(ri[1]<le[0])ret[1] = ri[1];
		else ret[1] = le[0];
	}
	
	
	if(le[2]>ri[2]){
		ret[2] = le[2];
		if(le[3]>ri[2])ret[3] = le[3];
		else ret[3] = ri[2];
	}
	else {
		ret[2] = ri[2];
		if(ri[3]>le[2])ret[3] = ri[3];
		else ret[3] = le[2];
	}
	
	return ret;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = {st[le],MOD,st[le],0};
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = merge(tree[lc], tree[rc]);
	return;
}

ari(4) que(int id,int le,int ri){
	if(le>=a && ri<=b)return tree[id];
	int mid = le+ri>>1;
	if(a<=mid && mid+1<=b)return merge(que(lc,le,mid), que(rc,mid+1,ri));
	if(a<=mid)return que(lc,le,mid);
	return que(rc,mid+1,ri);
}

void dfs(int nw){
	st[nw] = ++id;
	cv[id] = nw;
	for(int i:v[nw]){
		sp[0][i] = nw;
		dep[i] = dep[nw]+1;
		dfs(i);
	}
	en[nw] = id;
	return;
}

int get(int a,int b){
	int nw = cv[a];
	if(en[nw]>=b)return nw;
	rap(i,16,0)if(sp[i][nw]){
		if(en[sp[i][nw]]<b)nw = sp[i][nw];
	}
	return sp[0][nw];
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,2,n){
		cin>>a;
		v[a].pb(i);
	}
	dfs(1);
	build(1,1,n);
	rep(i,1,16)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]];
	while(q--){
		cin>>a>>b;
		ret = que(1,1,n);
		a = get(ret[1],ret[2]), b = get(ret[0],ret[3]);
//		rep(i,0,3)cout<<ret[i]<<" "; cout<<endl;
		if(dep[a]>dep[b]){
			cout<<cv[ret[0]]<<' '<<dep[a]<<endl;
		}
		else {
			cout<<cv[ret[2]]<<' '<<dep[b]<<endl;
		}
	}
	return 0;
}