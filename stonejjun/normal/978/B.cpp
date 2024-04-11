#include<stdio.h>

int main(){
	int i,k,cnt=0,ans=0;
	char c;
	scanf("%d",&k);
	getchar();
	for(i=1;i<=k;i++)
	{
		scanf("%c",&c);
		if(c=='x')
		{
		  cnt++;
		}
		else 
		{
		cnt=0;
		}
		if(cnt>2)
		{
		ans++;
		}
	}
	printf("%d",ans);
}