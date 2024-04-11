#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
long long lim=1000000000000000LL;
int a,b,h,w,n;
int ans;
int A[100100];
void dfs(int a,int b,int c){
	if(!a&&!b){
		ans=min(ans,c);
		return;
	}
	if(c==n) return;
	if(A[c]==2){
		while(a>0) a/=2,++c;
		while(b>0) b/=2,++c;
		ans=min(ans,c);
		return;
	}
	if(a) dfs(a/A[c],b,c+1);
	if(b) dfs(a,b/A[c],c+1);
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&w,&h,&n);
	ans=n+1;
	for(int i=0;i<n;++i) scanf("%d",A+i);
	std::sort(A,A+n,[&](int a,int b){return a>b;});
	dfs((a-1)/h,(b-1)/w,0);
	dfs((a-1)/w,(b-1)/h,0);
	printf("%d\n",ans==n+1?-1:ans);
	return 0;
}