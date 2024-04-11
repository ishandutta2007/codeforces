#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e5+10;
int T,n,a[o],ans;bool flg;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int calc(int x){
	int res=0;
	for(int i=1;i<=n;++i) if(a[i]&(1<<x)) ++res;
	return res;
}
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);ans=n;
		for(int i=flg=1;i<=n;++i) read(a[i]),flg&=!a[i];
		if(flg){for(int i=1;i<=n;++i) printf("%d ",i);continue;}
		ans=calc(0);
		for(int i=1;i<30;++i) ans=gcd(ans,calc(i));
		for(int i=1;i<=ans;++i) if(ans%i==0) printf("%d ",i);
	}
	return 0;
}