#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=1e6+10,MOD=998244353;
#define int long long
int n,k,hsh[o],pw[o];char s[o];
inline int g(int l,int r){return (hsh[r]+MOD-hsh[l-1]*pw[r-l+1]%MOD)%MOD;}
inline bool f(int x,int y){int l=0,r=n,md;while(l^r){md=(l+r>>1)+1;if(g(x,x+md-1)==g(y,y+md-1)) l=md;else r=md-1;}return l!=n&&s[x+l]<s[y+l];}
signed main(){
	read(n);read(k);scanf("%s",s+1);
	for(int i=1;i<=n;++i) s[n+i]=s[i];
	for(int i=pw[0]=1;i<=2*n;++i) hsh[i]=(hsh[i-1]*27+s[i]-96)%MOD,pw[i]=pw[i-1]*27%MOD;
	for(int i=2;i<=n;++i) if(f(1,i)) n=i-1;
	for(int i=1,j=1;i<=k;++i,j%=n,++j) putchar(s[j]);
	return 0;
}