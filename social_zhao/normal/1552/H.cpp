#include<bits/stdc++.h>
const int N=200050;
using namespace std;

int s,nw,ans=256,p,n=200;

int main(){
//	freopen("data.out","w",stdout);
	printf("? %d\n",n*n);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			printf("%d %d ",i,j);
	putchar('\n');
	fflush(stdout);
	scanf("%d",&s);
	int l=1,r=7;
	while(l<=r){
		int mid=((l+r)>>1),m=1<<mid;
		printf("? %d\n",n/m*n);
		for(int i=m;i<=n;i+=m)
			for(int j=1;j<=n;j++)
				printf("%d %d ",i,j);
		putchar('\n');
		fflush(stdout);
		scanf("%d",&nw);
		if(nw*m!=s)r=mid-1,p=nw,ans=m;
		else l=mid+1;
	}
	int a=abs(s/(ans>>1)-p*2)-1,b=s/(a+1)-1;
	printf("! %d\n",(a+b)*2);
	fflush(stdout);
}