#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 0x7f7f7f7f
using namespace std;

#define g() getchar()
template<class Q>inline void Scan(Q&x){
	char c; int f=1;
	while(c=g(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
	x*=f;
}

const int MAXN=4005;

int n,a[MAXN][MAXN];

inline int w(int i,int j){
	return (a[j][j]-a[j][i-1])-(a[i-1][j]-a[i-1][i-1]);
}

int k,f[2][MAXN];

void dp(int*pre,int*cur,int l,int r,int pl,int pr){
	if(l>r)return;
	int mid=(l+r)>>1,p=pl;
	cur[mid]=inf;
	for(int i=pl,R=min(mid-1,pr),tmp;i<=R;++i)
		if((tmp=pre[i]+w(i+1,mid))<cur[mid]){
			cur[mid]=tmp,p=i;
		}
	dp(pre,cur,l,mid-1,pl,p);
	dp(pre,cur,mid+1,r,p,pr);
}

inline void Init(){
	Scan(n),Scan(k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			Scan(a[i][j]);
			a[i][j]+=a[i][j-1];
		}
		for(int j=1;j<=n;++j){
			a[i][j]+=a[i-1][j];
		}
	}
}

inline void Solve(){
	int cur=0;
	for(int i=1;i<=n;++i){
		f[cur][i]=w(1,i);
	}
	for(int i=2;i<=k;++i){
		cur^=1;		
		dp(f[cur^1],f[cur],1,n,i-1,n-1);
	}
	printf("%d\n",f[cur][n]>>1);
}

inline void set_IO(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
}

int main(){
	//set_IO();
	Init(),Solve();
	return 0;
}