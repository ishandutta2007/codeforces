#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,x[MAX],z,lz[1<<20],val,cnt[1<<20],st[1<<20],a,b;
pii ret,tree[1<<20];
 
void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = {x[le],le};
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
 
pii que(int id,int le,int ri){
	if(ri<=z)return tree[id];
	if(le>z)return {0,0};
	int mid = le+ri>>1;
	return max(que(lc,le,mid), que(rc,mid+1,ri));
}
 
void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = {0,0};
		return;
	}
	int mid = le+ri>>1;
	if(z<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

inline void f(int id,int le,int ri){
	st[id]+= lz[id];
	if(le!=ri)lz[lc]+= lz[id], lz[rc]+= lz[id];
	lz[id] = 0;
	return;
}

void isi(int id,int le,int ri){
	if(le==ri){
		cnt[id]++;
		return;
	}
	int mid = le+ri>>1;
	if(z<=mid)isi(lc,le,mid);
	else isi(rc,mid+1,ri);
	cnt[id] = cnt[lc] + cnt[rc];
	return;
}

int qu(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(ri<z || st[id]<0 || !cnt[id])return 0;
	if(le==ri)return le;
	int mid = le+ri>>1, t1 = qu(lc,le,mid);
	return t1 ? t1 : qu(rc,mid+1,ri);
}

void up(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = val; f(id,le,ri); return;}
	int mid = le+ri>>1;
	up(lc,le,mid), up(rc,mid+1,ri);
	st[id] = max(st[lc],st[rc]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    build(1,1,n);
    rep(i,1,n){
    	cout<<tree[1].fi<<' ';
    	cin>>z;
    	a = z, b = n;
    	isi(1,1,n);
    	z = qu(1,1,n);
    	val = 1, up(1,1,n);
    	z = que(1,1,n).se;
    	upd(1,1,n);
    	a = z, b = n;
    	val = -1, up(1,1,n);
	}
	return 0;
}