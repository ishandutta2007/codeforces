#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1010;
#define int long long
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
int n,a[o],b[o],ans;
signed main(){
	read(n);n/=2;
	for(int i=1;i<=n;++i) read(a[i]),read(b[i]),ans+=Min(a[i],b[i]);
	for(int i=1;i<=n;++i) for(int j=i+1,v=-b[i],mn=-b[i];j<=n;++j)
		v+=a[j]-b[j],ans+=Max(0,Min(a[i],-v)+mn+1),mn=Min(v,mn);
	printf("%lld",ans); 
	return 0;
}