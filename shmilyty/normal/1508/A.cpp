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
int t,n;
string s[4];
void solve()
{
	n=read();
	cin>>s[1];
	cin>>s[2];
	cin>>s[3];
	int cnt1=0,cnt2=0,cnt3=0;
	while(cnt1<2*n&&cnt2<2*n&&cnt3<2*n)
	{
		if(s[1][cnt1]==s[2][cnt2])
		{
			cout<<s[1][cnt1];
			cnt1++;
			cnt2++;
		}
		else 
		if(s[2][cnt2]==s[3][cnt3])
		{
			cout<<s[3][cnt3];
			cnt2++;
			cnt3++;
		}
		else
		if(s[1][cnt1]==s[3][cnt3])
		{
			cout<<s[3][cnt3];
			cnt1++;
			cnt3++;
		}
	}
	if(cnt1==2*n)
	{
		if(cnt3>cnt2)
			for(int i=cnt3;i<2*n;i++)
				cout<<s[3][i];
		else
			for(int i=cnt2;i<2*n;i++)	
				cout<<s[2][i];
	}
	if(cnt2==2*n)
	{
		if(cnt1>cnt3)
			for(int i=cnt1;i<2*n;i++)
				cout<<s[1][i];
		else
			for(int i=cnt3;i<2*n;i++)	
				cout<<s[3][i];
	}
	if(cnt3==2*n)
	{
		if(cnt1>cnt2)
			for(int i=cnt1;i<2*n;i++)
				cout<<s[1][i];
		else
			for(int i=cnt2;i<2*n;i++)
				cout<<s[2][i];
	}
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}