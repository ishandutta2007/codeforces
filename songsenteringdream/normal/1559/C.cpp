#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1e5+10;
int T,n,a[o];
inline void slv(){
	for(int i=1;i<n;++i) if(a[i+1]&&!a[i]){
		for(int j=1;j<=i;++j) write(j),putchar(' ');
		write(n+1);putchar(' ');
		for(int j=i+1;j<=n;++j) write(j),putchar(' ');
		return;
	}
	if(!a[n]){for(int i=1;i<=n+1;++i) write(i),putchar(' ');return;}
	if(a[1]){write(n+1);putchar(' ');for(int i=1;i<=n;++i) write(i),putchar(' ');return;}
}
int main(){
	for(read(T);T--;putchar('\n')){read(n);for(int i=1;i<=n;++i) read(a[i]);slv();}
	return 0;
}