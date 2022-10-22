#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
const int o=1e5+10,inf=1e9+10;
int T,m,ans,s1[o],s2[o];
int main(){
	for(read(T);T--;putchar('\n')){
		read(m);ans=inf;
		for(int i=1;i<=m;++i) read(s1[i]),s1[i]+=s1[i-1];
		for(int i=1;i<=m;++i) read(s2[i]),s2[i]+=s2[i-1];
		for(int i=1;i<=m;++i) ans=Min(ans,Max(s1[m]-s1[i],s2[i-1]));
		write(ans);
	}
	return 0;
}