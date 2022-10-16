#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
inline int read()
{
	int x=0;
	bool flag=1;
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
/*
case1:aababbbbbcdef
	2(x):aabaaaaacbbbbbcdef
	2:aabababababacacacac
	3(x):aabababababababa
	3:abaaaaaaacbbbbcdef
	4:abbbbbbbbbbaaaaaa
*/
int t,n,num[120];
string s;
void outp()
{
	for(char i='a';i<='z';i++)
		for(int l=0;l<num[i-'a'];l++)
			cout<<i;
	cout<<endl;
}
void solve()
{
	char A='0',B='0',C='0';
	cin>>s;
	n=s.size();
	for(char i='a';i<='z';i++)
		num[i-'a']=0;
	for(int i=0;i<n;i++)
		num[s[i]-'a']++;
	for(char i='a';i<='z';i++)
		if(num[i-'a']==1)
		{
			cout<<i;
			num[i-'a']--;
			outp();
			return ;
		}
	for(char i='a';i<='z';i++)
		if(num[i-'a'])
		{
			if(A=='0')
			{
				A=i;
				continue;
			}
			if(B=='0')
			{
				B=i;
				continue;
			}
			if(C=='0')
			{
				C=i;
				break;
			}
		}
	if(num[A-'a']==n)
	{
		cout<<s<<endl;
		return ;
	}
	if(num[A-'a']<=3)
	{
		cout<<A<<A<<B;
		num[A-'a']-=2;
		num[B-'a']--;
		outp();	
		return ;
	}
	if(num[A-'a']-2<=n-num[A-'a'])
	{
		cout<<A<<A;
		num[A-'a']-=2;
		for(char i=A+1;i<='z';i++)
			for(int l=0;l<num[i-'a'];l++)
			{
				cout<<i;
				if(num[A-'a'])
				{
					num[A-'a']--;
					cout<<A;
				}
			} 
		puts("");
		return ;
	}
	if(C!='0')
	{
		cout<<A<<B;
		num[A-'a']--;
		num[B-'a']--;
		for(int l=0;l<num[A-'a'];l++)
			cout<<A;
		num[A-'a']=0;
		cout<<C;
		num[C-'a']--;
		outp();
		return ; 
	}
	cout<<A;
	num[A-'a']--;
	for(int i=0;i<num[B-'a'];i++)
		cout<<B; 
	for(int i=0;i<num[A-'a'];i++)
		cout<<A;
	puts("");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}