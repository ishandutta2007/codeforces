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
int t,n,k,sum,num[26];
string s,ans,cnt;
void dfs(int x)
{
//	cout<<x<<" "<<cnt<<endl;
	if(x==n)
	{
		ans=cnt;
		return ;
	}
	cnt+=s[x];
	num[s[x]-'a']++;
	if(num[s[x]-'a']%k==1)
		sum++;
	if(sum*k<=n) 
		dfs(x+1);
	if(ans!="")
		return ;
	if(num[s[x]-'a']%k==1)
		sum--;
	num[s[x]-'a']--;
	cnt=cnt.substr(0,cnt.size()-1);
//	cout<<x<<endl;
	for(char i=s[x]+1;i<='z';i++)
	{
//		cout<<"i="<<i<<endl;
		cnt+=i;
		num[i-'a']++;
		if(num[i-'a']%k==1)
			sum++;
		if(sum*k<=n)
		{
			string ad="";
			for(char l='a';l<='z';l++)
				while(num[l-'a']%k!=0)
				{
					ad+=l;
					num[l-'a']++;	
				}	
			while((int)cnt.size()+(int)ad.size()!=n)
				cnt+="a";
			ans=cnt+ad;
			return ;
		}
		if(num[i-'a']%k==1)
			sum--;
		num[i-'a']--;
		cnt=cnt.substr(0,cnt.size()-1);
	}
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		memset(num,0,sizeof(num));
		sum=0;
		cnt="";
		ans="";
		cin>>s;
		if(n%k!=0)
		{
			puts("-1");
			continue;
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}