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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 2010405347;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 312;

int n,m,k,q,x[MAX],a,b;
ll tree[1<<18],lz[1<<18],key = 36671, hs[MAX], inv;
char c;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le]; return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = (tree[lc]*hs[ri-mid] + tree[rc])%MOD;
	return;
}

inline void f(int id,int le,int ri){
	tree[id] = lz[id]*(hs[ri-le+1]-1)%MOD*inv%MOD;
//	if(le==ri && le==3)cout<<"HAI\n", db(lz[id]);
	if(le!=ri)lz[lc] = lz[rc] = lz[id];
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(le>b||ri<a){if(lz[id])f(id,le,ri); return;}
	if(le>=a&&ri<=b){lz[id] = c; f(id,le,ri); return;}
	if(lz[id])lz[lc] = lz[rc] = lz[id], lz[id] = 0;
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = (tree[lc]*hs[ri-mid] + tree[rc])%MOD;
	return;
}

ll que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return 0;
//	cout<<">> "<<id<<' '<<le<<' '<<ri<<endl;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	if(b<=mid)return que(lc,le,mid);
	else if(a>mid)return que(rc,mid+1,ri);
	return (que(lc,le,mid)*hs[min(ri,b)-mid] + que(rc,mid+1,ri))%MOD;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs[0] = 1;
    rep(i,1,100000)hs[i] = hs[i-1]*key%MOD;
    inv = pw(key-1,MOD-2);
    cin>>n>>m>>k; q = m+k;
    rep(i,1,n)cin>>c, x[i] = c;
    build(1,1,n);
//    a = 2, b = 3;
//    db(x[2]*hs[1]+x[3]);
//    db(que(1,1,n));
//    a = b = 2;
//    db(que(1,1,n));
//    db(tree[4]);
//    return 0;
    int ty,A,B,per,rem,len;
    bool st;
    ll tmp;
    while(q--){
    	cin>>ty>>a>>b;
    	if(ty==1){
    		cin>>c;
    		upd(1,1,n);
//    		db(tree[1]);
//    		a = b = 3;
//    		db(que(1,1,n));
		}
		else {
			cin>>k;
			A = a, B = b;
			b = a+k-1;
//			cout<<"<> "<<a<<' '<<b<<endl;
			tmp = que(1,1,n);
//			db(tmp);
			len = B-A+1;
//			db(len);
			per = len/k, rem = len%k;
			st = 1;
			if(per>1){
//				db(tmp);
//				cout<<">> "<<(hs[per*k]-1)%MOD*pw(hs[per]-1,MOD-2)%MOD<<endl;
//				cout<<"<> "<<hs[per*k]<<' '<<hs[per]<<endl;
				tmp = tmp*(hs[per*k]-1)%MOD*pw(hs[k]-1,MOD-2)%MOD;
//				db(tmp);
				b = a+per*k-1;
				st&= tmp==que(1,1,n);
			}
			if(st && rem){
//				cout<<"HAI\n";
				b = a+rem-1;
				tmp = que(1,1,n);
				b = B, a = b-rem+1;
				st&= tmp==que(1,1,n);
			}
			cout<<(st ? "YES" : "NO")<<endl;
		}
	}
    return 0;
}