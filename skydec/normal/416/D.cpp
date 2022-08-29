#include<stdio.h>
#include<cstring>
using namespace std;
int n;int xs;int l1,l2;
int a[210000];
int main()
{
	scanf("%d",&n);int ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);int head=1;
	while(head<=n)
	{
        //printf("%d\n",head);
		int l1,l2;l1=l2=0;int d1=0;
		int i=head;int fr=0;
		while(i<=n)
		{
			if(a[i]==-1&&!fr)fr=i;
			if(a[i]!=-1&&(!l1||!l2))
			{
				if(!l1)l1=i;
				else 
				{
					l2=i;
					if((a[l2]-a[l1])%(l2-l1)!=0)
					{
						head=i-1;
						ans++;
						break;
					}
					d1=(a[l2]-a[l1])/(l2-l1);
					if(fr==head)
					{
						if(a[l1]-(l1-fr)*1ll*d1<=0)
						{
							head=i-1;
							ans++;
							break;
						}
					}
				}
			}
			else
			{
				if(a[i]==-1&&l1&&l2)
				{
					if(d1*1ll*(i-l2)+a[l2]<=0)
                    {
							head=i-1;
							ans++;
							break;
						}
                    }
                 else
                 {
                     if(a[i]!=-1)
                     if(d1*1ll*(i-l2)+a[l2]!=a[i])       
                     {
							head=i-1;
							ans++;
							break;
						}
                    }    
                    }
                    i++;
      }
      if(i>n){ans++;break;}
      head++;
      }
      printf("%d\n",ans);
      return 0;
}