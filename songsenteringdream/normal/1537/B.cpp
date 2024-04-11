#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n,m;
int main(){
	for(read(T);T--;read(n),read(m)) read(n),read(m),printf("1 1 %d %d\n",n,m);
	return 0;
}