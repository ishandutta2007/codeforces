#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int N=120000;
int n,m,x[N],y[N],px[N],py[N];
LL ans;db midx,midy;int tmp[5];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		px[i]=x[i];py[i]=y[i];
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	if(n&1){
		midx=x[(n+1)/2];
		midy=y[(n+1)/2];
	}
	else{
		midx=1.*(x[n/2]+x[(n/2)+1])/2.;
		midy=1.*(y[n/2]+y[(n/2)+1])/2.;
	}
	rep(i,1,n){
		if(px[i]==midx&&py[i]==midy)tmp[4]=1;
		if(px[i]==midx||py[i]==midy)continue;
		int u=0;if(px[i]>midx)u+=2;if(py[i]>midy)u++;tmp[u]=1;
	}
	rep(i,1,n/2)ans+=1ll*(x[n-i+1]-x[i]+y[n-i+1]-y[i]);
	if(tmp[1]+tmp[2]+tmp[3]+tmp[0]<=2||((n&1)&&!tmp[4])){}
	else if(n&1){
		ans=max(ans-min(midx-x[n/2],x[n/2+2]-midx),ans-min(midy-y[n/2],y[n/2+2]-midy));
	}
	else{
		ans-=min(x[n/2+1]-x[n/2],y[n/2+1]-y[n/2]);
	}
	printf("%I64d\n",ans*2ll);
	return 0;
}