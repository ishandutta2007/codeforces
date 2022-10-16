#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string> 
using namespace std;
int t,n,x,y;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&y);
		int a=y-x;
		for(int i=n;i>=1;i--){
			if(a%(i-1)==0){
				int p=a/(i-1),j;
				for(j=1;j<=n;j++){
					if(x+(j-1)*p>y)break;
					printf("%d ",x+(j-1)*p);
				} 
				j--;
				j=n-j;
				for(int k=x-p;k>0&&j;k-=p)printf("%d ",k),j--;
				for(int k=y+p;j;k+=p)printf("%d ",k),j--;
				break;
			}
		}
		printf("\n");
	}
}