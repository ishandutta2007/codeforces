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
int n;
double p[18][18],f[1<<18];
signed main()
{
    f[1]=1;
    n=read();
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>p[i][j];
    for(int S=2;S<(1<<n);++S)
        for(int i=0;i<n-1;++i)
			if(S&(1<<i))
    			for(int j=i+1;j<n;++j)
                    if(S&(1<<j))
            	    	f[S]=max(f[S],f[S^(1<<i)]*p[j][i]+f[S^(1<<j)]*p[i][j]);
    cout<<f[(1<<n)-1];
}