#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
int T,n,a[o],s,k,p[o],q[o];
inline bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	for(read(T);T--;){
		read(n);read(k);s=0;
		for(int i=1;i<=n;++i) read(a[i]),p[i]=i;
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;++i) q[p[i]]=i;
		for(int i=1;i<n;++i) if(q[i]+1!=q[i+1]) ++s;
		if(s<k) printf("YES\n");else printf("NO\n");
	}
	return 0;
}