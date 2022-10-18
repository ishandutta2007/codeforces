#include<bits/stdc++.h>
using namespace std;
int n;
int te[100011];
int ke[100011];
int b[100011];
int re[100011];
int se[100011];
int BIT[100011];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)
{
	while(x<=n)
	{
		BIT[x]+=k;
		x+=lowbit(x);
	}
}
int get(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=BIT[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int q;
	scanf("%d %d",&q,&n);
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		add(y+1,-1);
		add(x,1);		
	}
	for(int i = 1;i<=n;i++)
	{
		te[i]=get(i);
		re[n+1-i] = te[i];
	}
	int cc = 0;
	for (int i = 1;i<=n;i++)
	{
		if (i==1) 
		{
			b[cc]=te[1];
		}
		else if (te[i]>=b[cc])
		{
			b[cc+1]=te[i];
			cc++;
		}
		else if (te[i]<b[cc])
		{
			if (te[i]>=b[0])
			{
				int cur = 1, d = log2(cc+1);
  				while (d>=0)
  				{
  					if (cur + (1<<d)<=cc&&te[i]>=b[cur + (1<<d)])
  					{
  	  					cur += 1<<d;
  					}
  					d--;
  				}
  				b[cur+1]=te[i];
			}
			else if (te[i]<b[1])
			{
				b[0]=te[i];
			}
 		}
 		ke[i]=cc;
	}
	cc = 0;
	memset(b,0,sizeof(b));
	for (int i = 1;i<=n;i++)
	{
		if (i==1) 
		{
			b[cc]=re[1];
		}
		else if (re[i]>=b[cc])
		{
			b[cc+1]=re[i];
			cc++;
		}
		else if (re[i]<b[cc])
		{
			if (re[i]>=b[0])
			{
				int cur = 1, d = log2(cc+1);
  				while (d>=0)
  				{
  					if (cur + (1<<d)<=cc&&re[i]>=b[cur + (1<<d)])
  					{
  	  					cur += 1<<d;
  					}
  					d--;
  				}
  				b[cur+1]=re[i];
			}
			else if (re[i]<b[0])
			{
				b[1]=re[i];
			}
 		}
 		se[n+1-i]=cc;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		ans = max(ans,se[i]+ke[i]+1);
	}
	printf("%d\n",ans);
  	return 0;
}