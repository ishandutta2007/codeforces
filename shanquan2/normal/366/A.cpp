#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int ans=-1,ans1=-1,ans2=-1;
	for(int i=0;i<4;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(min(a,b)+min(c,d)<=n){
			ans=i+1;
			ans1=min(a,b);
			ans2=n-ans1;
//			break;
		}
	}
	if(ans==-1)printf("-1\n");else
	printf("%d %d %d",ans,ans1,ans2);
	return 0;
}