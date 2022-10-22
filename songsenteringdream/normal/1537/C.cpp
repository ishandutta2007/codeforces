#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
const int o=2e5+10,inf=2e9+10;
int T,n,a[o],mn;
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);for(int i=1;i<=n;++i) read(a[i]);
		sort(a+1,a+1+n);
		mn=inf;for(int i=2;i<=n;++i) mn=Min(mn,a[i]-a[i-1]);
		for(int i=2;i<=n;++i) if(a[i]-a[i-1]==mn){mn=i;break;}
		write(a[mn-1]);for(int i=mn+1;i<=n;++i) putchar(' '),write(a[i]);
		for(int i=1;i<mn-1;++i) putchar(' '),write(a[i]);putchar(' ');write(a[mn]);
	}
	return 0;
}