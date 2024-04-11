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
int ans;
string s;
signed main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		int x=(s[i-1]-'0')*10+s[i]-'0';
		if(x%4==0)
			ans+=i;
		if((s[i]-'0')%4==0)
			ans++;
	} 
	if((s[0]-'0')%4==0)
		ans++;
	cout<<ans;
	return 0;
}