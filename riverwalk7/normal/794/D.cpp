#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int sd=400009,mm=1000000009;
struct edge{
	int t,next;
}g[810001];
struct edge2{
	int a,b;
}e[410001];
struct data{
	int n;
	ll v;
}w[410001];
set<pii> st;
int deg[410001],i,j,k,n,m,tot,h[410001],q[410001],b[410001],a[410001],num,cot;
pii mp(int x,int y){
	if (x>y) swap(x,y);
	return make_pair(x,y);
}
bool cmp(data x,data y){
	return x.v<y.v||x.v==y.v&&x.n<y.n;
}
void addedge(int x,int y){
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;
	g[++tot].t=x;g[tot].next=h[y];h[y]=tot;
}
void dfs(int x,int fa){
	int i;
	a[x]=++cot;
	for (i=h[x];i;i=g[i].next)
	 if (fa!=g[i].t) dfs(g[i].t,x);
}
int main(){
	scanf("%d%d",&n,&m);tot=0;memset(h,0,sizeof(h));
	for (i=1;i<=m;i++) scanf("%d%d",&e[i].a,&e[i].b),addedge(e[i].a,e[i].b);
	for (i=1;i<=n;i++){
		q[0]=1;q[1]=i;
		for (j=h[i];j;j=g[j].next) q[++q[0]]=g[j].t;
		sort(q+1,q+1+q[0]);w[i].n=i;
		for (w[i].v=0,j=1;j<=q[0];j++) w[i].v=(w[i].v*sd+q[j]);
	}
	sort(w+1,w+1+n,cmp);num=0;st.clear();memset(deg,0,sizeof(deg));tot=0;memset(h,0,sizeof(h));memset(a,0,sizeof(a));
	for (i=1;i<=n;i=j+1){
		for (j=i;j<n&&w[j+1].v==w[i].v;j++);
		for (k=i,num++;k<=j;k++) b[w[k].n]=num;
	}
	for (i=1;i<=m;i++)
	 if (b[e[i].a]!=b[e[i].b]&&!st.count(mp(b[e[i].a],b[e[i].b]))){
	 	st.insert(mp(b[e[i].a],b[e[i].b]));addedge(b[e[i].a],b[e[i].b]);
		deg[b[e[i].a]]++;deg[b[e[i].b]]++;
	 }
	for (i=1,k=0;k!=-1&&i<=num;i++){
		if (deg[i]>2) k=-1;
		if (deg[i]<=1) k=i;
	}
	if (k<1){
		puts("NO");return 0;
	}
	cot=0;dfs(k,0);
	puts("YES");
	for (i=1;i<=n;i++) printf("%d ",a[b[i]]);
	puts("");
	return 0;
}