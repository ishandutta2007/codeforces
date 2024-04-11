#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Max(long long a,long long b){return a>b?a:b;}
const int o=1e5+10,O=450;const long long inf=1e18;
int T,n;long long a[o],f[o][O];
inline void slv(){
	read(n);a[n+1]=0; 
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=n;i;--i) a[i]+=a[i+1];
	for(int i=1;i<=n+1;++i) for(int j=0;j<O;++j) f[i][j]=-inf;
	for(int i=1;i<=n+1;++i) f[i][0]=inf;
	for(int i=n;i;--i) for(int j=1;j<O;++j)
		f[i][j]=Max(f[i+1][j],(i+j<=n+1&&a[i]-a[i+j]<f[i+j][j-1])?a[i]-a[i+j]:-inf);
	for(int i=1;i;++i) if(f[1][i]<0){printf("%d\n",i-1);return;}
}
int main(){for(read(T);T--;slv());return 0;}