#include<bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int N = 1e5+10;

ll t,n,head[N],top,l[N],r[N],f[N][2];
struct osc{
	int to,next;
}a[N<<1];

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

inline ll abss(ll x){
	return x > 0 ? x : -x;
}

inline void dfs(int x,int fa){
	f[x][0] = f[x][1] = 0;
	for(int i=head[x];~i;i = a[i].next)
		if(a[i].to != fa){
			dfs(a[i].to,x);
			f[x][0] += max(f[a[i].to][0]+abss(l[a[i].to]-l[x]),f[a[i].to][1]+abss(r[a[i].to]-l[x]));
			f[x][1] += max(f[a[i].to][0]+abss(l[a[i].to]-r[x]),f[a[i].to][1]+abss(r[a[i].to]-r[x]));
		}
}

signed main()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i <= n;i++) head[i] = -1; top = 0;
		for(int i=1;i <= n;i++) scanf("%lld%lld",&l[i],&r[i]);
		int fr,to;
		for(int i=1;i < n;i++) scanf("%lld%lld",&fr,&to) , add(fr,to);
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}