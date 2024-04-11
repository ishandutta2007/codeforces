#include<bits/stdc++.h>
using namespace std;
#define in long long
inline in read()
{
    in X=0; 
	bool flag=1; 
	char ch=getchar();
    while(ch<'0'||ch>'9') 
	{
		if(ch=='-') 
			flag=0; 
		ch=getchar();
	}
    while(ch>='0'&&ch<='9') 
	{
		X=(X<<1)+(X<<3)+ch-'0'; 
		ch=getchar();
	}
    if(flag) 
		return X;
    return ~(X-1);
}
in t,n,a,b,ok=0;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		a=read();
		ok=0;
		for(in i=1;i<n;i++)
		{
			b=read();
			if(a<=b)
				ok=1;
			a=b;
		}
		if(ok)
			puts("Yes");
		else
			puts("No"); 
	}
	return 0;
}