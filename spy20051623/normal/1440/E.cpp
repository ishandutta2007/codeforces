#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];
int Mn[MAXN<<2], Mx[MAXN<<2];

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		Mn[id]=Mx[id]=seg[id]=A[tl];
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];	
}
inline void add_lazy(int id, int len, ll val){
	Mn[id]=val;
	Mx[id]=val;
	lazy[id]=val;
	seg[id]=len*val;
}
inline void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}
void Maximize(int id, int tl, int tr, int pos, ll val){
	if (pos<=tl || val<=Mn[id]) return ;
	if (tr<=pos && Mx[id]<=val){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, pos, val);
	Maximize(id<<1 | 1, mid, tr, pos, val);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}
int BS1(int id, int tl, int tr, int pos, ll val){
	if (tr<=pos || val<Mn[id]) return tr;
	if (tr-tl==1) return tl;
	shift(id, tl, tr);
	int mid=(tl+tr)>>1, tmp=BS1(id<<1, tl, mid, pos, val);
	if (tmp==mid) return BS1(id<<1 | 1, mid, tr, pos, val);
	return tmp;
}
int BS2(int id, int tl, int tr, ll val){
	if (seg[id]<=val) return tr;
	if (tr-tl==1) return tl;
	shift(id, tl, tr);
	int mid=(tl+tr)>>1, tmp=BS2(id<<1, tl, mid, val);
	if (tmp<mid) return tmp;
	return BS2(id<<1 | 1, mid, tr, val-seg[id<<1]);
}
ll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	Build(1, 1, n+1);
	while (m--){
		cin>>t>>x>>y;
		if (t==1) Maximize(1, 1, n+1, x+1, y);
		else{
			ans=0;
			while (1){
				x=BS1(1, 1, n+1, x, y);
				if (x==n+1) break ;
				ll val=y+Get(1, 1, n+1, 1, x);
				int xx=BS2(1, 1, n+1, val);
				// buy [x, xx)
				ans+=xx-x;
				y-=Get(1, 1, n+1, x, xx);
				x=xx;
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}