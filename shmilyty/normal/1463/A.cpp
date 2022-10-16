#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
inline int read() 
{
	int s=0,f=0;
	char ch=getchar();
	while(ch<48||ch>57)f=(ch=='-'),ch=getchar();
	while(ch>47&&ch<58)s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return f?-s:s;
}
int main() 
{
	T=read();
	while(T--) 
    {
		a=read(),b=read(),c=read();
		int sum=a+b+c,tmp=min(min(a,b),c);
		if(sum%9!=0)puts("NO");
		else if(sum/9>tmp)puts("NO");
		else puts("YES");
	}
	return 0;
}