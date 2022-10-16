#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[2333],t[2333];
int a[2333];
inline bool ok(int pos)
{
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		if(t[i])
			tot+=abs(i-pos);
	}
	return tot==a[pos];
}
int cnt[2333];
int mk[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>(s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			cnt[s[i]-'a']++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		memset(t,0,sizeof(t));
		for(char ch='z';ch>='a';ch--)
		{
			memset(mk,0,sizeof(mk));
			int cur=0;
			for(int j=1;j<=m;j++)
			{
				if(t[j])continue;
				if(ok(j))
				{
					cur++;
					mk[j]=1;
				}
			}
//			cerr<<ch<<' '<<cur<<' '<<cnt[ch-'a']<<endl;
			if(cnt[ch-'a']>=cur)
			{
				for(int j=1;j<=m;j++)
				{
					if(mk[j])
					{
						t[j]=ch;
					}
				}
			}
		}
		cout<<t+1<<endl;
	}
	return 0;
}