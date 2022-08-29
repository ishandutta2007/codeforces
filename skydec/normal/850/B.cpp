#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=2010000;
const int M=2000000;
int sum[N];
LL spos[N];
int n,a[N],x,y;
LL ans=0;
int main(){
	scanf("%d%d%d",&n,&x,&y);
	ans=n*1ll*x;
	rep(i,1,n){
		scanf("%d",&a[i]);
		sum[a[i]]++;
		spos[a[i]]+=a[i];
	}
	rep(i,1,M)sum[i]+=sum[i-1],spos[i]+=spos[i-1];
	int d=x/y;
	//-1 chao guo d
	rep(p,2,M){
		int nowcnt=0;
		LL res=0;
		for(int i=p;i<=M;i+=p){
			int l=i-min(p-1,d);
			//l..i -> i
			res+=(i*1ll*(sum[i]-sum[l-1])-(spos[i]-spos[l-1]))*1ll*y;
			nowcnt+=sum[i]-sum[l-1];
		}
		res+=(n-nowcnt)*1ll*x;
		if(res<ans)ans=res;
	}
	printf("%I64d\n",ans);
	return 0;
}