#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
//inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,s,ty,a,b,c,nw;
pll tree[1<<18];
ll lz[1<<18],val,ans[MAX];
vector<ari(2)> ed[1<<18];
vector<ari(3)> v[MAX];

void build(int id,int le,int ri){
	if(le==ri){
		if(le!=s)tree[id].fi = INF;
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id].fi = min(tree[lc].fi,tree[rc].fi);
	return;
}

inline void f(int id,int le,int ri){
	if(tree[id].se!=ri-le+1)tree[id].fi = min(tree[id].fi,lz[id]);
	if(le!=ri){
		if(lz[lc])lz[lc] = min(lz[lc],lz[id]);
		else lz[lc] = lz[id];
		if(lz[rc])lz[rc] = min(lz[rc],lz[id]);
		else lz[rc] = lz[id];
	}
	lz[id] = 0;
	return;
}

void add(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>a||ri<a)return;
	++tree[id].se;
	if(le==ri){
		tree[id].fi = INF;
		return;
	}
	int mid = le+ri>>1;
	add(lc,le,mid), add(rc,mid+1,ri);
	tree[id].fi = min(tree[lc].fi,tree[rc].fi);
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lz[id] = val;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id].fi = min(tree[lc].fi,tree[rc].fi);
	return;
}

ll que(int id,int le,int ri){
	if(le==ri){
		val = tree[id].fi;
		return le;
	}
	int mid = le+ri>>1;
	if(lz[lc])f(lc,le,mid);
	if(lz[rc])f(rc,mid+1,ri);
	if(tree[lc].se==mid-le+1)return que(rc,mid+1,ri);
	if(tree[rc].se==ri-mid || tree[lc].fi < tree[rc].fi)return que(lc,le,mid);
	return que(rc,mid+1,ri);
}

void isi(int id,int le,int ri){
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		ed[id].pb({c,(int)val});
		return;
	}
	int mid = le+ri>>1;
	isi(lc,le,mid), isi(rc,mid+1,ri);
	return;
}

void trav(int id,int le,int ri){
	for(ari(2) i:ed[id]){
		v[a].pb({i[0],i[0],i[1]});
	}
	ed[id].clear();
	if(le==ri)return;
	int mid = le+ri>>1;
	if(a<=mid)trav(lc,le,mid);
	else trav(rc,mid+1,ri);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	build(1,1,n);
	while(m--){
		cin>>ty;
		if(ty==1){
			cin>>a>>b>>val;
			v[a].pb({b,b,(int)val});
		}
		else if(ty==2){
			cin>>a>>b>>c>>val;
			v[a].pb({b,c,(int)val});
		}
		else {
			cin>>c>>a>>b>>val;
			isi(1,1,n);
		}
	}
	rep(i,1,n){
		a = que(1,1,n);
		add(1,1,n);
		ans[a] = val;
		if(val==INF)continue;
		trav(1,1,n);
		nw = a;
		for(ari(3) j:v[nw]){
			a = j[0], b = j[1], val = ans[nw] + j[2];
			upd(1,1,n);
		}
	}
	rep(i,1,n){
		if(ans[i]==INF)ans[i] = -1;
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}