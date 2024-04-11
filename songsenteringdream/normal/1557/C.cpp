#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%lld",a)
const int MOD=1e9+7;
#define int long long
int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*b%MOD) if(f&1) res=res*b%MOD;return res;}
int T,n,k;
signed main(){
	for(read(T);T--;putchar('\n')){
		read(n);read(k);
		if(n&1) write(qp(qp(2,n-1)+1,k));
		else{
			int ans=0;
			for(int i=0;i<k;++i) ans=(ans+qp(qp(2,n-1)-1,i)*qp(qp(2,n),k-i-1))%MOD;write((ans+qp(qp(2,n-1)-1,k))%MOD);
		}
	}
	return 0;
}