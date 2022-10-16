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
int n,xo[65537]; 
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		cout<<"XOR "<<i<<" "<<i+1<<endl;
		cout.flush();
		xo[i]=read();	
		if(xo[i]==-1)
			return 0;
	} 
	puts("OR 1 2"); 
	cout.flush();
	int or12=read();
	if(or12==-1)
		return 0;
	int and12=or12-xo[1];
	int sum12=and12+or12;
	puts("OR 2 3");
	cout.flush();
	int or23=read();
	if(or23==-1)
		return 0;
	int and23=or23-xo[2];
	int sum23=and23+or23;
	puts("OR 1 3");
	cout.flush();
	int or13=read();
	if(or13==-1)
		return 0;
	int and13=or13-(xo[1]^xo[2]);
	int sum13=and13+or13;
	int summ=(sum12+sum13+sum23)/2;
	int x=summ-sum23;
	cout<<"! "<<x<<" ";
	for(int i=1;i<n;i++)
	{
		x^=xo[i];
		cout<<x<<" "; 
	}
	return 0;
}