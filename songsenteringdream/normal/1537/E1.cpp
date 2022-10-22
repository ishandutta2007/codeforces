#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=1e4+10;
int n,k;char s[o];
inline bool f(int x,int y){for(int i=1;i<=n;++i,++x,++y) if(s[x]<s[y]) return true;else if(s[x]>s[y]) return false;return false;}
int main(){
	read(n);read(k);scanf("%s",s+1);
	for(int i=1;i<=n;++i) s[n+i]=s[i];
	for(int i=2;i<=n;++i) if(f(1,i)) n=i-1;
	for(int i=1,j=1;i<=k;++i,j%=n,++j) putchar(s[j]);
	return 0;
}