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
int t,n,k,num1[26],num2[26];
string a,b;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		cin>>a>>b;
		for(int i=0;i<26;i++)
			num1[i]=num2[i]=0;
		for(int i=0;i<n;i++)
			num1[a[i]-'a']++;
		for(int i=0;i<n;i++)
			num2[b[i]-'a']++;
		bool flag=1;
		for(int i=0;i<25;i++)
		{
			if(num1[i]<num2[i])
			{
				flag=0;
				break;	
			} 
			if(num1[i]>num2[i])
			{
				if(num1[i]%k!=num2[i]%k)
				{
					flag=0;
					break;
				}
				else
					num1[i+1]+=num1[i]-num2[i];
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}