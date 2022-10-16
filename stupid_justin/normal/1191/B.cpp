#include<bits/stdc++.h>
#define N 1000005
#define MOD 1e9+7
#define inf 0x3f3f3f3f
using namespace std;
bool work(int  x,int  y,int  z)
{
	if (x==y && y==z) return 1;
	if (x==y-1 && y==z-1) return 1;//xyz
	if (x==z-1 && z==y-1) return 1;//xzy
	if (y==x-1 && x==z-1) return 1;//yxz
	if (y==z-1 && z==x-1) return 1;//yzx
	if (z==x-1 && x==y-1) return 1;//zxy
	if (z==y-1 && y==x-1) return 1;//zyx
	return 0;
}
bool work2(int  x,int  y,int  z)
{
	if ((abs(x-y)==0 || abs(x-y)==1)|| abs(x-y)==2) return 1;
	if ((abs(y-z)==0 || abs(y-z)==1)|| abs(y-z)==2) return 1;
	if ((abs(z-x)==0 || abs(z-x)==1)|| abs(z-x)==2) return 1;
	return 0;
}
bool work3(int  x,int  y)
{
	if ((abs(x-y)==0 || abs(x-y)==1)|| abs(x-y)==2) return 1;
	return 0;
}
signed main()
{
	string s[3];
	int  number[3],type[3];
	for (int  i=0;i<3;i++) cin>>s[i];
	for (int  i=0;i<3;i++)
	{
		number[i]=int(s[i][0]);
		type[i]=s[i][1];
	}
	if (type[0]==type[1] && type[1]==type[2])
	{
		if (work(number[0],number[1],number[2])) 
		{
			cout<<"0"<<endl;
			return 0;
		}
		if (work2(number[0],number[1],number[2]))
		{
			cout<<"1"<<endl;
			return 0;
		}
		cout<<"2"<<endl;
		return 0;
	}
	if (type[0]==type[1])
	{
		if (work3(number[0],number[1])) 
		{
			cout<<"1"<<endl;
			return 0;
		}
	}
	if (type[2]==type[1])
	{
		if (work3(number[2],number[1])) 
		{
			cout<<"1"<<endl;
			return 0;
		}
	}
	if (type[0]==type[2])
	{
		if (work3(number[0],number[2])) 
		{
			cout<<"1"<<endl;
			return 0;
		}
	}
	if (type[0]!=type[1] && (type[1]!=type[2] &&type[2]!=type[0]))
	{
		cout<<"2"<<endl;return 0;
	}
	cout<<"2"<<endl;
	return 0;
}