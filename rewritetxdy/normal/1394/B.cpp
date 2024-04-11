#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int n,m,k,vis[12][12][12][12],a[12],d[N],top = 2;
struct osc{
	int f,t,w,v;
}c[N];
int ans;

inline int cmp(osc x,osc y){
	return x.t < y.t || (x.t == y.t && (x.v < y.v || (x.v == y.v && x.w < y.w)));
}

inline int cmp2(osc x,osc y){
	return x.f < y.f || (x.f == y.f && x.w < y.w);
}

inline void dfs(int x){
	if(x > k){
		ans++;
		return;
	}
	for(int i=1;i <= x;i++){
		a[x] = i;
		int f = 0;
		for(int j=1;j <= x;j++)
			if(vis[j][a[j]][x][a[x]]){
				f = 1; break;
			}
			if(f) continue;
			dfs(x+1);
	}
}

int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i <= m;i++) scanf("%d%d%d",&c[i].f,&c[i].t,&c[i].w) , d[c[i].t]++;
	for(int i=1;i <= n;i++) if(!d[i]){
		puts("0");
		return 0;
	}
	sort(c+1,c+1+m,cmp2);
	int las = 1;
	for(int i=1;i <= m;i++) if(c[i].f != c[i+1].f){
		for(int x=las;x <= i;x++)
			c[x].w = x-las+1 , c[x].v = i-las+1;
		las = i+1;
	}
	sort(c+1,c+1+m,cmp);
//	for(int i=1;i <= m;i++) cout<<c[i].f<<' '<<c[i].t<<' '<<c[i].v<<' '<<c[i].w<<endl;
//	cout<<endl;
	for(int i=3;i <= m;i++){
		if(c[i].t == c[top-1].t && c[i].v == c[top-1].v && c[i].w == c[top-1].w){
//			cout<<c[i].f<<' '<<c[i].t<<' '<<c[i].v<<' '<<c[i].w<<"==="<<endl;
			continue;
		}
		c[++top] = c[i];
	}
	m = top; c[m+1].t = 0; //oscar little sister carry me QAQ
//	for(int i=1;i <= m;i++) cout<<c[i].f<<' '<<c[i].t<<' '<<c[i].v<<' '<<c[i].w<<endl;
	las = 1;
	for(int i=1;i <= m;i++) if(c[i].t != c[i+1].t){
		for(int x=las;x <= i;x++)
			for(int y=x+1;y <= i;y++)
				vis[c[x].v][c[x].w][c[y].v][c[y].w] = vis[c[y].v][c[y].w][c[x].v][c[x].w] = 1;
		las = i+1;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}