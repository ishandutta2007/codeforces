#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=3010; 
int T,n,a[o];bool flg;
inline int rev(int p){for(int i=1,j;i*2<p;++i) j=a[i],a[i]=a[p-i+1],a[p-i+1]=j;}
void slv(int n){
	if(n==1) return;
	for(int i=1;i<=n;++i) if(a[i]==n){printf("%d ",i);rev(i);break;}
	for(int i=2;i<=n;++i) if(a[i]==n-1){printf("%d %d ",i-1,i+1);rev(i-1);rev(i+1);break;}
	printf("3 %d ",n);rev(3);rev(n);slv(n-2);
}
int main(){
	for(read(T);T--;flg=0){
		read(n);for(int i=1;i<=n;++i) read(a[i]),flg|=((a[i]^i)&1);
		if(flg){printf("-1\n");continue;}
		printf("%d\n",n/2*5);
		slv(n);putchar('\n');
	}
	return 0;
}