#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
int n,m,k,ans,f[1<<10][1<<10];
vector<int> a[10];
signed main()
{
	n=read();
	m=read();
	k=read();
	while(m--)
	{
		int x=read()-1,y=read()-1;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<(1<<n);i<<=1)
		f[i][i]=1;
	for(int i=1;i<(1<<n);i++)
		for(int l=i;l;--l&=i)
			if(f[i][l])
				for(int j=0;j<n;j++)
					if(i&(1<<j))
						for(int to:a[j])
							if(~i&(1<<to))
							{
								int now=0;
								if(__builtin_popcount(i)==1)
									now=i|(1<<to);
								else
									now=l&~(1<<j)|(1<<to);
                                if(!(now>>to+1))
								    f[i|(1<<to)][now]+=f[i][l];
							}
	for(int i=0;i<=(1<<n)-1;i++) 
	    if(__builtin_popcount(i)==k)
	       ans+=f[(1<<n)-1][i];
	cout<<ans;
	return 0;
}