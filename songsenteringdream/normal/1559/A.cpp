#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1010;
int T,n,a[o];
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);for(int i=1;i<=n;++i) read(a[i]);
		for(int i=2;i<=n;++i) a[1]&=a[i];
		write(a[1]);
	}
	return 0;
}