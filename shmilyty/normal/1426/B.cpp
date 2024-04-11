#include<bits/stdc++.h>
#define int long long
inline int read()
{
    int X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}
int t,n,m,a,b,c,d,ok;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		ok=0;
		while(n--)
		{
			a=read();
			b=read();
			c=read();
			d=read();
			if(b==c)
				ok=1; 
		}
		if(m%2==0&&ok)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}