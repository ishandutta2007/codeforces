#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
int T,a,b;
int main(){
	for(read(T);T--;putchar('\n')){
		read(a);read(b);
		if(a>b) a+=b,b=a-b,a=a-b;
		if((a+b)%2==0){
			printf("%d\n",a+1);
			for(int i=(a+b)/2-a,j=(a+b)/2+a;i<=j;i+=2) printf("%d ",i);
		}
		else{
			printf("%d\n",2*a+2);
			for(int i=b-(a+b+1)/2,j=(a+b+1)/2+a;i<=j;++i) printf("%d ",i);
		}
	}
	return 0;
}