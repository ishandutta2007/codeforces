#include<stdio.h>
#include<algorithm>
int main(){
	int n,k,i,j,cnt=0,arra[1000],arrb[1000],arrc[2000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  scanf("%d",&arra[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		k=arra[i];
		arrc[k]=arrc[k]+1;
		if(arrc[k]==1)
		{

			arrb[cnt]=arra[i];
			cnt++;
		}
		
	}
	printf("%d\n",cnt);
	for(j=cnt-1;j>=0;j--)
	{
		printf("%d ",arrb[j]);
	}
}