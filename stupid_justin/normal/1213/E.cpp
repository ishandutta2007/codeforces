#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
char ch(char x,char y)
{
	if (x!=y)
	if (x=='a' && y=='b') return 'c';
	if (x=='a' && y=='c') return 'b';
	if (x=='b' && y=='a') return 'c';
	if (x=='b' && y=='c') return 'a';
	if (x=='c' && y=='a') return 'b';
	if (x=='c' && y=='b') return 'a';
}
int main()
{
	int n;
	cin>>n;
	string str1;
	string str2;
	cin>>str1>>str2;
	cout<<"YES"<<endl;
	if (str1[0]!=str1[1] && str2[0]!=str2[1])
	{
		if (str1[0]==str2[0])
		{
			if (str1[0]=='a')
			{
				for (int i=1;i<=n;i++) cout<<'b';
				for (int i=1;i<=n;i++) cout<<'c';
				for (int i=1;i<=n;i++) cout<<'a';
			}
			if (str1[0]=='b')
			{
				for (int i=1;i<=n;i++) cout<<'a';
				for (int i=1;i<=n;i++) cout<<'c';
				for (int i=1;i<=n;i++) cout<<'b';
			}
			if (str1[0]=='c')
			{
				for (int i=1;i<=n;i++) cout<<'b';
				for (int i=1;i<=n;i++) cout<<'a';
				for (int i=1;i<=n;i++) cout<<'c';
			}
		}else
		
		
		if (str1[1]==str2[1])
		{
			if (str1[1]=='a')
			{
				for (int i=1;i<=n;i++) cout<<'a';
				for (int i=1;i<=n;i++) cout<<'b';
				for (int i=1;i<=n;i++) cout<<'c';
			}
			if (str1[1]=='b')
			{
				for (int i=1;i<=n;i++) cout<<'b';
				for (int i=1;i<=n;i++) cout<<'a';
				for (int i=1;i<=n;i++) cout<<'c';
			}
			if (str1[1]=='c')
			{
				for (int i=1;i<=n;i++) cout<<'c';
				for (int i=1;i<=n;i++) cout<<'b';
				for (int i=1;i<=n;i++) cout<<'a';
			}
		}else
		
		if (str1[1]==str2[0])
		{
			if (str1[0]==str2[1])
			{
				for (int i=1;i<=n;i++) cout<<str1[1];
				for (int i=1;i<=n;i++) cout<<ch(str1[1],str1[0]);
				for (int i=1;i<=n;i++) cout<<str1[0];
			}else
			{
				for (int i=1;i<=n;i++) cout<<str2[1];
				for (int i=1;i<=n;i++) cout<<str1[1];
				for (int i=1;i<=n;i++) cout<<str1[0];
			}
				
		}else
		
		if (str1[0]==str2[1])
		{
			for (int i=1;i<=n;i++) cout<<str1[1];
			for (int i=1;i<=n;i++) cout<<str2[1];
			for (int i=1;i<=n;i++) cout<<str2[0];
		}
	}
	else
	if (str1[0]==str1[1] && str2[0]==str2[1])
	{
		for (int i=1;i<=n;i++) cout<<"abc";
	}
	else
	
	
	if (str1[0]==str1[1])
	{
		if (str2[0]==str1[0])
		{
			for (int i=1;i<=n;i++) cout<<str1[0]<<ch(str1[0],str2[1]);
			for (int i=1;i<=n;i++) cout<<str2[1];
		}else
		if (str2[1]==str1[0])
		{
			for (int i=1;i<=n;i++) cout<<str1[0]<<ch(str1[0],str2[0]);
			for (int i=1;i<=n;i++) cout<<str2[0];
		}else
		for (int i=1;i<=n;i++) cout<<str1[0]<<str2[1]<<str2[0];
	}else
	
	
	if (str2[1]==str2[0])
	{
		if (str1[0]==str2[0])
		{
			for (int i=1;i<=n;i++) cout<<str2[0]<<ch(str2[0],str1[1]);
			for (int i=1;i<=n;i++) cout<<str1[1];
		}else
		if (str1[1]==str2[0])
		{
			for (int i=1;i<=n;i++) cout<<str2[0]<<ch(str2[0],str1[0]);
			for (int i=1;i<=n;i++) cout<<str1[0];
		}else
		for (int i=1;i<=n;i++) cout<<str2[0]<<str1[1]<<str1[0];
	}
}