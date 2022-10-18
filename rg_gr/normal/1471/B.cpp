#include <cstdio>
#include <ctype.h>
#define il inline
#define int long long
using namespace std;
const int maxn=100005;
const int INF=(int)(1e9)+7;
int n,dd,t,minn,pos;
int a[maxn],sum[maxn];
int ans;
inline int read(){
	char ch=getchar();	int ret=0,f=1;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret;
}
signed main(){
	int k,j,i;
	t=read();
	while(t--){
		minn=INF;
		n=read();   dd=read();  ans=0;
		for(k=1;k<=n;k++){
			int x=read();   int p=dd,cnt=1;
			while(!(x%p))  p*=dd,cnt++;
			a[k]=cnt;    sum[k]=sum[k-1]+x;
			if(cnt<minn){
				minn=cnt;
				pos=k;
			}
		}
		printf("%lld\n",1ll*sum[n]*minn+sum[pos-1]);
	}
	return 0;
}