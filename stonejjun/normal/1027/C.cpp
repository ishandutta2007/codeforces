#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,i,j,lo,n,chk,a,b,x,y,temp,dis,len;

	
	scanf("%lld",&t);
	while(t--)
	{
		x=0,y=0,temp=0,dis=0,len=0;
		
		int chk[11111]={0};
		int arr[11111]={0};
		
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			arr[x]++;
			if(arr[x]==2) 
			{
			len++;
			chk[len]=x;
			}
		}
		
		sort(chk+1,chk+len+1);
		
		for(j=1;j<=len;j++)
		{
			i=chk[j];
			if(arr[i]>=4)
			{
				x=i;
				y=i;
				break;
			}
			
			if(arr[i]>=2)
			{
				if(dis!=0)
				{
					if( (x*i)<(y*temp) )
					{
						x=temp;
						y=i;
						dis=1;
						
					}
				}
				else if(temp!=0)
				{
					x=temp;
					y=i;
					dis=1;
				}
				
				
				temp=i;
			}
			
			
		}
		
		printf("%lld %lld %lld %lld\n",x,x,y,y);
		
	}
	
	
}