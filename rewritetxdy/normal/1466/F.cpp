#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5+10;
const int p = 1e9+7;

int n,m,fa[N],sz[N],q[N],top;

inline int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline ll pw(ll x,int y){
	ll ans = 1;
	while(y){
		if(y&1) ans = ans*x%p;
		x = x*x%p , y >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i <= m;i++) fa[i] = i , sz[i] = 1;
	int k,x,y;
	for(int i=1;i <= n;i++){
		scanf("%d",&k);
		if(k == 1){
			scanf("%d",&x);
			if(find(x) != find(0)){
				sz[find(0)] += sz[find(x)];
				fa[find(x)] = find(0);
				q[++top] = i;
			}
		}
		else{
			scanf("%d%d",&x,&y);
			if(find(x) != find(y)){
				sz[find(y)] += sz[find(x)];
				fa[find(x)] = find(y);
				q[++top] = i;
			}
		}
	}
	ll ans = 1;
	for(int i=0;i <= m;i++) if(fa[i] == i) ans = ans*pw(2ll,sz[i]-1)%p;
	printf("%lld %d\n",ans,top);
	for(int i=1;i <= top;i++) printf("%d ",q[i]);
	puts("");
	return 0;
}