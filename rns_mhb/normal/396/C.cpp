#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
#define M 601001
#define pb push_back
#define sz size
typedef __int64 ll;
const ll mod = 1000000007;
vector<int>chi[M];
char bs[M];
int dis[M], fin[M], dn, fn, cnt, s[2*M], p[M], pre[M], nxt[M], D[M], F[M];
ll da[M], db[M], dc[M], fa[M], fb[M], fc[M];
int n;
const int MM = M/2;
void add(ll *t, int k, ll v){while(k<MM)t[k]+=v, t[k]>=mod?t[k]-=mod:0, k+=(k&-k);}
ll sum(ll *t, int k, ll s=0){while(k)s+=t[k], k-=(k&-k);return s%mod;}

void dfs(int u){
	dis[u]=++dn;
	s[++cnt]=u;	D[u]=cnt; bs[cnt]='(';
	for(int i=0; i<chi[u].sz(); i++){
		dfs(chi[u][i]);
	}
	fin[u]=++fn;
	s[++cnt]=u;	F[u]=cnt; bs[cnt]=')';
}
int main(){
	int i, j, k, Q, type, u, v, x, t;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		scanf("%d", &k);
		chi[k].pb(i);
	}
	{
		dfs(1);
		int last=0;
		for(i=1; i<=2*n; i++){
			pre[i]=last;
			if(bs[i]=='(') last=s[i];
		}
		last=0;
		for(i=1; i<=2*n; i++){
			p[i]=last;
			if(bs[i]==')')last=s[i];
		}
		last=n+1;
		for(i=2*n; i; i--){
			nxt[i]=last;
			if(bs[i]==')') last=s[i];
		}
	}

	int l, r;
	for(scanf("%d", &Q); Q--; ){
		scanf("%d", &type);
		if(type==1){
			scanf("%d %d %d", &u, &x, &t);
			if(t<0)t+=mod;
			x+=t;
			if(x>=mod)x-=mod;
			{
				l=dis[u];
				r=dis[pre[F[u]]];
				k=mod-t;
				add(da, l, k);	add(da, r+1, mod-k);
				add(db, l, mod-(1ll*k*(l-1)%mod)),	add(db, r+1, 1ll*k*r%mod);

				add(db, l, x);	add(db, r+1, mod-x);
			}
			{
				r=fin[u];
				l=fin[nxt[D[u]]];

				k=t;

				add(fa, l, k);	add(fa, r+1, mod-k);
				add(fb, l, mod-(1ll*k*(l-1)%mod)),	add(fb, r+1, 1ll*k*r%mod);
			}
		}else{
			scanf("%d", &u);
			int dd=dis[u], ff=fin[p[D[u]]];
			ll xx = sum(da,dd)*dd + sum(db,dd);
			ll yy = sum(fa,ff)*ff + sum(fb,ff);

			xx += yy;
			xx %= mod;
			if(xx<0)xx+=mod;
			printf("%I64d\n", xx);
		}
	}
	return 0;
}