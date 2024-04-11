#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=4e5+10;
#define int long long
int T,n,m,a[o],b[o],h[o],cnt,U,V,s1,s2,col[o];bool flg;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){for(int i=h[nw];i;i=e[i].p) if(col[e[i].v]){if(col[e[i].v]==col[nw]) flg=1;}else col[e[i].v]=3-col[nw],dfs(e[i].v);}
signed main(){
	for(read(T);T--;){
		read(n);read(m);
		for(int i=1;i<=n;++i) col[i]=h[i]=0,read(a[i]);
		s1=s2=cnt=flg=0;
		for(int i=1;i<=n;++i) read(b[i]),b[i]-=a[i];
		for(int i=1;i<=m;++i) read(U),read(V),ad(U,V),ad(V,U);
		dfs(col[1]=1);
		for(int i=1;i<=n;++i) if(col[i]==1) s1+=b[i];else s2+=b[i];
		if((s1+s2)&1) printf("NO\n");
		else if(flg) printf("YES\n");
		else printf(s1==s2?"YES\n":"NO\n");
	}
	return 0;
}