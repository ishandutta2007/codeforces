#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],a,b,bc[MAX],pf[MAX],ans,cnt,id,st[MAX],en[MAX],ds,tree[1<<19],lz[1<<19],val,res,at,anak;
bool stat;
int dep[MAX],sp[18][MAX];
map<int,int> hs;
vector<int> v[MAX],isi[MAX],tmp[MAX];

void dfs(int nw,int par){
	st[nw] = ++id;
	for(int i:v[nw])if(i!=par){
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		tmp[nw].pb(i), dfs(i,nw);
	}
	en[nw] = id;
	return;
}
inline void f(int id,int le,int ri){
	tree[id]+= lz[id];
	if(le!=ri)lz[lc]+= lz[id], lz[rc]+= lz[id];
	lz[id] = 0; return;
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
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
int que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return max(que(lc,le,mid), que(rc,mid+1,ri));
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	rap(i,17,0)if(dep[x]-(1<<i)>=dep[y])x = sp[i][x];
	if(x==y)return x;
	rap(i,17,0){
		if(sp[i][x]!=sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], hs[x[i]];
    for(auto i:hs)hs[i.fi] = ++ds;
    rep(i,1,n)x[i] = hs[x[i]], isi[x[i]].pb(i);
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dep[1] = 1;
	dfs(1,0);
	rep(j,1,17)rep(i,1,n)sp[j][i] = sp[j-1][sp[j-1][i]];
	rep(i,1,n)v[i] = tmp[i];
	
	id = 0;
	rep(i,1,ds)if(isi[i].size()>1){
		at = isi[i][0], val = 1;
		for(int j:isi[i])a = st[j], b = en[j], upd(1,1,n), at = lca(at,j);
		stat = 1;
		for(int j:isi[i])if(j==at){
			stat = 0;
			break;
		}
		if(stat)a = st[at], b = en[at], upd(1,1,n);
		
		for(int j:isi[i]){
			a = b = st[j];
			val = que(1,1,n), anak = 0;
			for(int k:v[j]){
				a = st[k], b = en[k];
				res = que(1,1,n) - val;
				if(res){
					if(j!=at || anak)return cout<<"0\n",0;
					anak = k;
				}
			}
			if(!anak)++bc[st[j]], --bc[en[j]+1];
			else {
				a = st[anak], b = en[anak];
				++pf[a], --pf[b+1];
				++id;
			}
		}
		val = -1;
		for(int j:isi[i])a = st[j], b = en[j], upd(1,1,n);
		if(stat)a = st[at], b = en[at], upd(1,1,n);
	}
	rep(i,1,n){
		bc[i]+= bc[i-1], pf[i]+= pf[i-1];
		if(!bc[i] && pf[i]==id)++ans;
	}
	cout<<ans<<endl;
    return 0;
}