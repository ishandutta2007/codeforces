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
string ans;
char s[100002];
int n,m,num[10],a[100002],lin[100002][64];
vector<int> t[100002];
bool check(int x)
{
	for(int i=0;i<64;i++)
	{
		int tmp=0;
		for(int j=0;j<6;j++)
			if(i>>j&1)
				tmp+=num[j];		
		if(lin[x][i]<tmp)
			return 0;
	}
	return 1;
}
signed main()
{
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		num[s[i]-'a']++;
	m=read();
	while(m--)
	{
		int pos=read();
		string tmp;
		cin>>tmp;
		for(auto y:tmp)
		{
			t[pos].push_back(y-'a');
			a[pos]|=(1<<y-'a');
		}
	}
	for(int i=1;i<=n;i++)
		if((int)t[i].size()==0)
		{
			a[i]=63;
			for(int l=0;l<6;l++)
				t[i].push_back(l);
		}
	for(int i=n;i>=1;i--)
		for(int l=0;l<64;l++)
			if(l&a[i])
				lin[i][l]=lin[i+1][l]+1;
			else
				lin[i][l]=lin[i+1][l];
	for(int i=1;i<=n;i++)
	{
		sort(t[i].begin(),t[i].end());
		for(auto x:t[i])
		{
			num[x]--;
			if(check(i+1))
			{
				ans.push_back(x+'a');
				break;
			}
			num[x]++;
		}
	}
	if((int)ans.size()<n)
		puts("Impossible");
	else
		cout<<ans;
	return 0;
}