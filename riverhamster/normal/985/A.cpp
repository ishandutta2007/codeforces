#include <stdio.h>
#include <math.h>
#include <algorithm>
using std::sort;
int a[10005];
int n,m,x;
inline int min(int a,int b){return a<b?a:b;}
int check(int type){
	int ans=0;
	for(int i=1;i<=m;i++){
		// printf("%d %d %d\n",type+i*2-2,a[i],abs(a[i]-type-i*2+2));
		ans+=abs(a[i]-type-i*2+2);
	}
	// printf("ans=%d\n",ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	while(~scanf("%d",&x)){
		a[++m]=x;
	}
	sort(a+1,a+1+m);
	printf("%d\n",min(check(1),check(2)));
	return 0;
}