#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n,a,s; 
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);s=0;for(int i=1;i<=n;++i) read(a),s+=a;
		if(s<n) putchar('1');
		else if(s==n) putchar('0');
		else write(s-n); 
	}
	return 0;
}