#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1010;
int T,n,a[o];
inline bool chk(){for(int i=1;i<n;++i) if(a[i]>a[i+1]) return false;return true;}
inline void chg(int x){
	if(x) for(int i=1,j;i<n;i+=2) if(a[i]>a[i+1]) j=a[i],a[i]=a[i+1],a[i+1]=j;else;
	else for(int i=2,j;i<n;i+=2) if(a[i]>a[i+1]) j=a[i],a[i]=a[i+1],a[i+1]=j;
}
int main(){
	for(read(T);T--;){
		read(n);for(int i=1;i<=n;++i) read(a[i]);
		for(int i=0;1;chg((++i)&1)) if(chk()){printf("%d\n",i);break;}
	}
	return 0;
}