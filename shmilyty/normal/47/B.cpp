#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
string s;
int a[4]={0,1,2,3},b[4][4];
map<char,int> to; 
signed main()
{
	to['A']=1;
	to['B']=2;
	to['C']=3;
	for(int i=1;i<=3;i++)
	{
		cin>>s;
		if(s[1]=='>')
			b[to[s[0]]][to[s[2]]]=1;
		else
			b[to[s[2]]][to[s[0]]]=1;
	}
	do{
		bool ok=1;
		for(int i=1;i<=2;i++)
			for(int l=i+1;l<=3;l++)
				if((a[i]>a[l])!=b[i][l])
					ok=0;
		if(ok)
		{
			for(int i=1;i<=3;i++)
				if(a[i]==1)
					cout<<char('A'-1+i);
			for(int i=1;i<=3;i++)
				if(a[i]==2)
					cout<<char('A'-1+i);
			for(int i=1;i<=3;i++)
				if(a[i]==3)
					cout<<char('A'-1+i);
			return 0;
		}
	}while(next_permutation(a+1,a+4));
	puts("Impossible");
	return 0;
}