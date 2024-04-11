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
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 312;

int k;
struct tr{
	int mk[10][10];
	int l,r;
}tree[1<<19];
int n,m,lz[1<<19],x[MAX],a,b;
char c;
string s;

void build(int id,int le,int ri){
	if(le==ri){tree[id].l = tree[id].r = x[le]; return;}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id].l = tree[lc].l, tree[id].r = tree[rc].r;
	rep(i,0,k)rep(j,0,k)tree[id].mk[i][j] = tree[lc].mk[i][j] + tree[rc].mk[i][j];
	++tree[id].mk[tree[lc].r][tree[rc].l];
	return;
}
inline void f(int id,int le,int ri){
	tree[id].l = tree[id].r = lz[id];
	mems(tree[id].mk,0);
	tree[id].mk[lz[id]][lz[id]] = ri-le;
	if(le!=ri)lz[lc] = lz[rc] = lz[id];
	lz[id] = -1;
	return;
}
void upd(int id,int le,int ri){
	if(lz[id]!=-1)f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lz[id] = c; f(id,le,ri); return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id].l = tree[lc].l, tree[id].r = tree[rc].r;
	rep(i,0,k)rep(j,0,k)tree[id].mk[i][j] = tree[lc].mk[i][j] + tree[rc].mk[i][j];
	++tree[id].mk[tree[lc].r][tree[rc].l];
	return;
}
int ans,ty;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k; --k;
	rep(i,1,n)cin>>c, x[i] = c-'a';
	build(1,1,n);
	mems(lz,-1);
	while(m--){
		cin>>ty;
		if(ty==1){
			cin>>a>>b>>c;
			c-='a';
			upd(1,1,n);
		}
		else {
			cin>>s;
			ans = 1;
			rep(i,0,k)rep(j,i,k)ans+= tree[1].mk[s[j]-'a'][s[i]-'a'];
			cout<<ans<<endl;
		}
	}
    return 0;
}