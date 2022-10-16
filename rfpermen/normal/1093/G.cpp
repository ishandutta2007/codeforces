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
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,k,q,x[MAX][5],y[MAX][16],z,a,b,ans,tmp;
pii tree[3*MAX][16],res;

void build(int id,int le,int ri,int mask){
	if(le==ri){tree[id][mask] = {le,le}; return;}
	int mid = le+ri>>1;
	build(lc,le,mid,mask), build(rc,mid+1,ri,mask);
	
	if(y[tree[lc][mask].fi][mask]>y[tree[rc][mask].fi][mask])tree[id][mask].fi = tree[lc][mask].fi;
	else tree[id][mask].fi = tree[rc][mask].fi;
	if(y[tree[lc][mask].se][mask]<y[tree[rc][mask].se][mask])tree[id][mask].se = tree[lc][mask].se;
	else tree[id][mask].se = tree[rc][mask].se;
	return;
}
void upd(int id,int le,int ri,int mask){
	if(le==ri)return;
	
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid,mask);
	else upd(rc,mid+1,ri,mask);
	
	if(y[tree[lc][mask].fi][mask]>y[tree[rc][mask].fi][mask])tree[id][mask].fi = tree[lc][mask].fi;
	else tree[id][mask].fi = tree[rc][mask].fi;
	if(y[tree[lc][mask].se][mask]<y[tree[rc][mask].se][mask])tree[id][mask].se = tree[lc][mask].se;
	else tree[id][mask].se = tree[rc][mask].se;
	return;
}
pii que(int id,int le,int ri,int mask){
	if(le>=a&&ri<=b)return tree[id][mask];
	int mid = le+ri>>1;
	pii t1,t2;
	if(a<=mid)t1 = que(lc,le,mid,mask);
	if(b>mid)t2 = que(rc,mid+1,ri,mask);
	if(a<=mid&&b>mid){
		pii ret;
		if(y[t1.fi][mask]>y[t2.fi][mask])ret.fi = t1.fi;
		else ret.fi = t2.fi;
		if(y[t1.se][mask]<y[t2.se][mask])ret.se = t1.se;
		else ret.se = t2.se;
		return ret;
	}
	else if(a<=mid)return t1;
	return t2;
}
int com;
int main(){
    scanf("%d%d",&n,&k); z = (1<<(k-1))-1, k--;
    rep(i,1,n){
    	rep(j,0,k)scanf("%d",&x[i][j]);
    	rep(j,0,z){
    		rep(o,0,k){
    			if(j&(1<<o))y[i][j]-=x[i][o];
    			else y[i][j]+=x[i][o];
			}
		}
	}
    rep(i,0,z)build(1,1,n,i);
    scanf("%d",&q);
    while(q--){
    	scanf("%d",&com);
    	if(com&1){
    		scanf("%d",&a);
    		rep(i,0,k)scanf("%d",&x[a][i]);
			rep(j,0,z){
				y[a][j] = 0;
	    		rep(o,0,k){
	    			if(j&(1<<o))y[a][j]-=x[a][o];
	    			else y[a][j]+=x[a][o];
				}
			}
    		rep(i,0,z)upd(1,1,n,i);
		}
		else {
			scanf("%d%d",&a,&b);
			ans = 0;
			rep(i,0,z){
				res = que(1,1,n,i);
				tmp = 0;
				rep(j,0,k)tmp+=abs(x[res.fi][j]-x[res.se][j]);
				ans = max(ans,tmp);
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}