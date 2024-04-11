#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=105,inf=0x3f3f3f3f;
int p[N],n;
int main(){
	scanf("%d",&n);
	rep(i,n>>1)scanf("%d",p+i);
	sort(p+1,p+(n>>1)+1);
	int ans=inf,cur=0;
	rep(i,n>>1)cur+=abs(p[i]-(2*i));
	ans=min(ans,cur);cur=0;
	rep(i,n>>1)cur+=abs(p[i]-(2*i-1));
	ans=min(ans,cur);
	printf("%d\n",ans);
	//system("pause");
}