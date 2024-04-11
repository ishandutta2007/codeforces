#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
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
const int block = 2000;

int n,k,ans[MAX],tree[1<<19],x[MAX],y[MAX],tgt,a,b,res,ls,val;
bool lz[1<<19];
piii q[MAX];

inline void f(int &id,int &le,int &ri){
	tree[id] = 0;
	if(le!=ri)lz[lc] = lz[rc] = 1;
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

void updp(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le==ri){tree[id] = val; return;}
	int mid = le+ri>>1;
	if(a<=mid)updp(lc,le,mid);
	else updp(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

int que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int le,ri,mid;
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i]; x[n+1] = 21e8;
    cin>>k;
    rep(i,1,k)cin>>q[i].fi>>q[i].sf, q[i].ss = i;
    sort(q+1,q+1+k);
    ls = n;
    rap(i,k,1){
    	while(ls!=q[i].fi){
    		--ls;
    		a = le = ls, ri = n, tgt = x[ls]+y[ls];
    		while(le<=ri){
    			mid = le+ri>>1;
    			if(x[mid]<=tgt)b = mid, le = mid+1;
    			else ri = mid-1;
			}
			if(a==b){
				val = x[ls+1] - tgt;
				updp(1,1,n);
			}
			else {
				--b; upd(1,1,n);
				a = b = b+1;
				val = que(1,1,n);
				if(val>x[b+1]-tgt){
					val = x[b+1]-tgt;
					updp(1,1,n);
				}
			}
		}
		a = q[i].fi, b = q[i].sf-1;
		ans[q[i].ss] = que(1,1,n);
	}
	rep(i,1,k)cout<<ans[i]<<endl;
    return 0;
}