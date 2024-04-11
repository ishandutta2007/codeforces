#include <bits/stdc++.h>
using namespace std;
string S;
int n,i;
int cal(string t)
{
	string s=S;
	if (isdigit(s[n-1])&&s[n-1]!=t[1]) return 0;
	if (isdigit(s[n-2])&&s[n-2]!=t[0]) return 0;
	if (n==2)
	{
		return t[0]!='0';
	}
	if (s[n-1]=='X')
	{
		for (int i=0;i<n;i++) if (s[i]=='X') s[i]=t[1];
		if (isdigit(s[n-2])&&s[n-2]!=t[0]) return 0;
		if (s[0]=='0') return 0;
		int ans=1;
		for (int i=1;i<n-2;i++) if (s[i]=='_') ans*=10;
		if (s[0]=='_') ans*=9;
		return ans;
	}
	if (s[n-2]=='X')
	{

		for (int i=0;i<n;i++) if (s[i]=='X') s[i]=t[0];
		if (isdigit(s[n-1])&&s[n-1]!=t[1]) return 0;
		if (s[0]=='0') return 0;
		int ans=1;
		for (int i=1;i<n-2;i++) if (s[i]=='_') ans*=10;
		if (s[0]=='_') ans*=9;
		return ans;
	}
		int ans=1;
		for (int i=1;i<n-2;i++) if (s[i]=='_') ans*=10;
		if (s[0]=='_') ans*=9;
		if (s[0]=='X') ans*=9; else
		{
			int i;
			for (i=0;i<n-2;i++) if (s[i]=='X') break;
			if (i<n-2) ans*=10;
		}
		return ans;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>S;
	string s=S;
	n=s.size();
	if (n==1)
	{
		if (s[0]=='0'||s[0]=='_'||s[0]=='X') cout<<1; else cout<<0;
		return 0;
	}
	if (s[0]=='0')
	{
		cout<<0;return 0;
	}
	if (n==2&&s[0]=='X'&&s[1]=='X')
	{
		cout<<0;return 0;
	}
	cout<<cal("00")+
	cal("25")+
	cal("50")+
	cal("75");
}