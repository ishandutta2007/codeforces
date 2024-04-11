#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,lo,chk;
	char c[1000];
	scanf("%d",&t);
	while(t--)
	{
		chk=1;
		scanf("%d",&lo);
		scanf("%s",c);
		
		for(i=0;i<=lo/2;i++)
		{
			j=c[i]-c[lo-1-i];
			if(j==2||j==0||j==-2)
			{
				;	
			}
			else
			{
				chk=0;
			}
			
		}
		if(chk) printf("YES\n");
		else printf("NO\n");
		
	}
}