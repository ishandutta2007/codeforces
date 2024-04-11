#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}
int t,n;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int x=sqrt(n);
		int y=(x-1)*2;
		n-=x*x;
		if(n==0)
			cout<<y<<endl;
		else
			if(n>x)
				cout<<y+2<<endl;
			else
				cout<<y+1<<endl; 
	} 
	return 0;
}