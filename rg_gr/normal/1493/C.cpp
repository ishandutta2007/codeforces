#include <stdio.h>
#include <string.h> 
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
char a[100005];
int t[26];
void erase(int &c,int k,int i)
{
	c-=((k-t[a[i]])%k+k)%k;
}
void ins(int& c,int k,int i)
{
	c+=((k-t[a[i]])%k+k)%k;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		scanf("%s",a);
		if(n%k)
		{
			puts("-1");
			continue;
		}
		memset(t,0,sizeof(t));
		for(int i=0;i<n;i++)
		{
			a[i]-=97;
			t[a[i]]++;
		}
		int c=0;
		for(int i=0;i<26;i++)c+=((k-t[i])%k+k)%k;
		int p=0;
		for(int i=n-1;i>=0;i--)
		{
			if(i==n-1)
			{
				if(c==0)
				{
					//print(n);
					for(int i=0;i<n;i++)putchar(a[i]+97);
					puts("");
					goto ng;
				}
			}
			for(int j=a[i]+1;j<26;j++)
			{
				erase(c,k,i);
				t[a[i]]--;
				ins(c,k,i);
				a[i]++;
				erase(c,k,i);
				t[a[i]]++;
				ins(c,k,i);
				if(c<=p)
				{
				//	printf("%d ",i);
					int cp=n-1;
					for(int i=25;i>=0;i--)
					{
						while(t[i]%k)t[i]++,a[cp--]=i;
					}
					for(int j=i+1;j<=cp;j++)a[j]=0;
					for(int i=0;i<=n-1;i++)putchar(a[i]+97);
					puts("");
					goto ng;
					goto ng;
				}
			}
			erase(c,k,i);
			t[a[i]]--;
			ins(c,k,i);
			p++;
			/*else
			{
				erase(c,k,i);
				t[a[i]]--;
				ins(c,k,i);
			}
			if(c<=p)
			{
			//	printf("")
				int cp=n-1;
				for(int i=25;i>=0;i--)
				{
					while(t[i]%k)t[i]++,a[cp--]=i;
				}
				for(int j=i+1;j<cp;j++)a[j]=0;
				for(int i=0;i<=n-1;i++)putchar(a[i]+97);
				puts("");
				goto ng;
			}
			else
			{
				c-=(k-t[a[i]])%k;
				t[a[i]]--;
				c+=(k-t[a[i]])%k;
			}
			p++;
			a[i-1]++;*/
		}
		ng:;
	}
}