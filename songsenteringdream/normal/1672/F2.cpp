#include<cstdio>
#include<queue>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o],c[o],mx,h[o],d[o],cnt;queue<int> q;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){++d[e[++cnt].v=V];e[cnt].p=h[U];h[U]=cnt;}
int main(){
	for(scanf("%d",&T);T--;mx=cnt=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) c[i]=d[i]=h[i]=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),++c[a[i]];
		for(int i=1;i<=n;++i) if(c[i]>c[mx]) mx=i;
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		for(int i=1;i<=n;++i) if(a[i]-mx&&b[i]-mx) ad(a[i],b[i]);
		for(int i=1;i<=n;++i) if(!d[i]) q.push(i);
		for(cnt=0;!q.empty();++cnt,q.pop())
			for(int i=h[q.front()];i;i=e[i].p) if(!--d[e[i].v]) q.push(e[i].v);
		printf(cnt==n?"AC\n":"WA\n");
	}
	return 0;
}