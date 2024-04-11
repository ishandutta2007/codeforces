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
const int MAX = 1e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2048;
const int uk = MAX/block + 5;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,idx,idy,tree[uk][block<<1],siz[uk],sz,a,b,ans[MAX],le[uk],ri[uk];
ari(6) x[MAX];
ari(3) sh[MAX];
map<int,int> hx;
vector<ari(3)> v[uk];
bool vis[MAX];

void build(int bc,int id,int le,int ri){
	if(le==ri){
		tree[bc][id] = v[bc][le-1][2];
		return;
	}
	int mid = le+ri>>1;
	build(bc,lc,le,mid), build(bc,rc,mid+1,ri);
	tree[bc][id] = min(tree[bc][lc],tree[bc][rc]);
	return;
}

void upd(int bc,int id,int le,int ri){
	if(le==ri){
		tree[bc][id] = MOD;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(bc,lc,le,mid);
	else upd(bc,rc,mid+1,ri);
	tree[bc][id] = min(tree[bc][lc],tree[bc][rc]);
	return;
}

int que(int bc,int id,int le,int ri){
	if(le>b || ri<a)return MOD;
	if(le>=a && ri<=b)return tree[bc][id];
	int mid = le+ri>>1;
	return min(que(bc,lc,le,mid), que(bc,rc,mid+1,ri));
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		rep(j,1,4)cin>>x[i][j];
		cin>>x[i][0];
		x[i][5] = i;
	}
	sort(x+1,x+1+n);
	cin>>m;
	rep(i,1,m)cin>>sh[i][0]>>sh[i][1], sh[i][2] = i;
	sort(sh+1,sh+1+m);
	rep(i,1,m){
		v[i/block].pb({sh[i][1],sh[i][0],sh[i][2]});
	}
	sz = m/block;
	rep(i,0,sz){
		le[i] = v[i][0][1], ri[i] = v[i].back()[1];
//		out(le[i],ri[i]);
		sort(all(v[i]));
		siz[i] = v[i].size();
		build(i,1,1,siz[i]);
	}
	
	int mn,res,pos;
	
	rep(i,1,n){
		mn = MOD, pos = -1;
		rep(k,0,sz){
			if(ri[k]<x[i][1])continue;
			if(le[k]>x[i][2])break;
			if(le[k]<x[i][1] || ri[k]>x[i][2]){
				for(ari(3) &j:v[k])if(j[2]<mn && !vis[j[2]] && x[i][1]<=j[1] && x[i][2]>=j[1]
															&& x[i][3]<=j[0] && x[i][4]>=j[0]){
					mn = j[2], pos = k;
				}
			}
			else if(!(x[i][3]>v[k].back()[0] || x[i][4]<v[k][0][0])){
				a = lower_bound(all(v[k]),ari(3){x[i][3],0,0}) - v[k].begin() + 1;
				b = lower_bound(all(v[k]),ari(3){x[i][4]+1,0,0}) - v[k].begin();
				res = que(k,1,1,siz[k]);
				if(res<mn)mn = res, pos = k;
			}
		}
		if(mn!=MOD){
			ans[mn] = x[i][5];
			vis[mn] = 1;
			For(j,0,siz[pos])if(v[pos][j][2]==mn){
				a = j+1;
				upd(pos,1,1,siz[pos]);
				break;
			}
		}
	}
	rep(i,1,m)cout<<ans[i]<<endl;
	return 0;
}