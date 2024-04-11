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
int ans,k,a[18][18];
string s;
void solve(int x,string ss)
{
	for(int i=1;i<=k;i++)
		if(!(x&(1<<(i-1))))
		{
			int flag=1;
			string t="";
			for(int l=0;l<ss.size();l++)
				if(ss[l]-'a'!=i-1)
				{
					if(!t.empty()&&!a[t[t.size()-1]-'a'+1][ss[l]-'a'+1])
					{
						flag=0;
						break;
					}
					t+=ss[l];
				}
			if(flag)
			{
				ans=min(ans,(long long)t.size());
				solve(x+(1<<(i-1)),t);
				break;
			}
		}
}
signed main()
{
	ans=read();
	k=read();
	cin>>s;
	for(int i=1;i<=k;i++)
		for(int l=1;l<=k;l++)
			a[i][l]=read();
	solve(0,s);
	cout<<ans; 
	return 0;
}