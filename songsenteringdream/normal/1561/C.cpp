#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
#define int long long
inline int Max(int a,int b){return a>b?a:b;}
int T,n,k,a[o];pair<int,int> p[o];
signed main(){
	for(read(T);T--;){
		read(n);
		for(int i=1;i<=n;++i){
			read(k);
			for(int j=0;j<k;++j) read(a[j]);a[k]=0;
			for(int j=k-1;j+1;--j) a[j]=Max(a[j+1],a[j]-j);
			p[i]=make_pair(a[0],k);
		}
		sort(p+1,p+1+n);
		for(int i=2,j=p[1].second;i<=n;j+=p[i++].second) p[i].first=Max(p[i-1].first,p[i].first-j);
		printf("%lld\n",p[n].first+1);
	}
	return 0;
}