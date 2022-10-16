#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,q,x,p[63],id,a,b;
ll tree[1<<20],lz[1<<20],f[305],v,res,ans,pre[63];
string s;

inline void zz(int &id,int &le,int &ri){
	tree[id]|=lz[id];
	if(le!=ri)lz[lc]|=lz[id], lz[rc]|=lz[id];
	lz[id] = 0;
}
void upd(int id,int le,int ri){
	if(lz[id])zz(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lz[id] = v; zz(id,le,ri); return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc]|tree[rc];
}
ll que(int id,int le,int ri){
	if(lz[id])zz(id,le,ri);
	if(le>b||ri<a)return 0 ;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid)|que(rc,mid+1,ri);
}
ll tree1[1<<20],lz1[1<<20];
ll fx(ll xx,ll yy){
	ll ret = 1;
	while(yy){
		if(yy&1)ret = (ret*xx)%MOD;
		xx = (xx*xx)%MOD;
		yy>>=1;
	}
	return ret;
}
inline void zz1(int &id,int &le,int &ri){
	tree1[id] = (fx(lz1[id],ri-le+1)*tree1[id])%MOD;
	if(le!=ri){
		lz1[lc] = (lz1[lc]*lz1[id])%MOD;
		lz1[rc] = (lz1[rc]*lz1[id])%MOD;
	}
	lz1[id] = 1;
}
void upd1(int id,int le,int ri){
	if(lz1[id]!=1)zz1(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lz1[id] = x; zz1(id,le,ri); return;
	}
	int mid = le+ri>>1;
	upd1(lc,le,mid), upd1(rc,mid+1,ri);
	tree1[id] = (tree1[lc]*tree1[rc])%MOD;
}
ll que1(int id,int le,int ri){
	if(lz1[id]!=1)zz1(id,le,ri);
	if(le>b||ri<a)return 1;
	if(le>=a&&ri<=b)return tree1[id];
	int mid = le+ri>>1;
	return (que1(lc,le,mid)*que1(rc,mid+1,ri))%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,2,300){
    	rep(j,2,i){
    		if(j==i)p[++id] = i;
    		if(i%j==0)break;
		}
	}
	rep(i,2,300)rep(j,1,id)if(i%p[j]==0)f[i]|=(1ll<<j);
	rep(i,1,id)pre[i] = fx(p[i],MOD-2);
	cin>>n>>q;
	rep(i,1,1048575)tree1[i] = lz1[i] = 1;
	rep(i,1,n){
		cin>>x;
		a = b = i, v = f[x];
		upd(1,1,n);
		upd1(1,1,n);
	}
	while(q--){
		cin>>s>>a>>b;
		if(s=="MULTIPLY"){
			cin>>x;
			v = f[x];
			upd(1,1,n);
			upd1(1,1,n);
//			rep(i,1,n){
//				a = b = i;
//				cout<<que1(1,1,n)<<' ';
//			}
//			a = 6, b = 7;
//			cout<<endl;
//			cout<<que1(1,1,n)<<endl;
		}
		else {
			res = que(1,1,n)>>1, ans = que1(1,1,n);
//			cout<<ans<<endl;
			rep(i,1,id){
//				cout<<(res&1);
				if(res&1)ans = (ans*pre[i])%MOD, ans = (ans*(p[i]-1))%MOD;
				res>>=1;
			}
//			cout<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}