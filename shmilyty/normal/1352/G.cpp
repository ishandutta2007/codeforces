#include <bits/stdc++.h>
#define pb push_back
using namespace std;

inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

int Q,n,a[10005],cnt;

int main()
{
	Q=read();
	for (;Q--;)
	{
		n=read();
		cnt=0;
		if(n==4)
		{
			puts("3 1 4 2");
			continue;
		}
		if(n<=3) 
			printf("-1");
		else 
		{
			if(n&1)
			{
				for ( int j=n;j>=1;j-- ) 
					if(j&1) a[++cnt]=j;
				a[++cnt]=4,a[++cnt]=2;
				if(n>=6)
					for ( int j=6;j<=n;j++ ) 
						if(j%2==0) a[++cnt]=j;
			}
			else 
			{
				for ( int j=n;j>=1;j-- ) 
					if(j%2==0) a[++cnt]=j;
				a[++cnt]=5,a[++cnt]=1,a[++cnt]=3;
				if(n>=7)
					for ( int j=7;j<=n;j++ ) 
						if(j&1) a[++cnt]=j;	
			}
			for ( int i=1;i<=cnt;i++ ) printf("%d ",a[i]);
		}
		puts(""); 
	}
}