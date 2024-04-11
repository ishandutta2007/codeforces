#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
int T,n,x;
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);
		if(n&1) printf("Bob");
		else{
			x=0;while(n%2==0) ++x,n>>=1;
			if(n!=1||x%2==0) printf("Alice");
			else printf("Bob");
		}
	}
	return 0;
}