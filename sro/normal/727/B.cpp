#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream> 
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string k;
long long a,b;

int get_it(string s)
{
	int X=0;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			X=X*10+s[i]-'0';;
		}
	}
	return X;
}

void tenjar(string s)
{
	int sz=s.size(),x=0,y=0;
	if(s.size()>=4&&s[sz-3]=='.')
	{
		x=get_it(s.substr(0,sz-3));
		y=get_it(s.substr(sz-2,2));
	}
	else
	{
		x=get_it(s);
		//y=get_it("00");
	}
	a+=x;
	b+=y;
}

int main()
{
	cin>>k;
	for(int i=0;i<k.size();i++)
	{
		if(isdigit(k[i]))
		{
			string linshinum="";
			while(i<k.size()&&(isdigit(k[i])||k[i]=='.'))
			{
				linshinum+=k[i];
				i++;
			}
			tenjar(linshinum);
			i--;
		}
	}
	a+=b/100;
	b%=100;
	
	string zheng="",xiao="";
	if(a==0) zheng="0";
	else
	{
		int myd=0;
		while(a)
		{
			if(myd==3)
			{
				myd=0;
				zheng+='.';
			}
			zheng+=a%10+'0';
			a/=10;
			myd++;
		}
		reverse(zheng.begin(),zheng.end());
	} 
	if(b)
	{
		while(b)
		{
			xiao+=b%10+'0';
			b/=10;
		}
		if(xiao.size()==1)
		{
			xiao+="0";
		}
		xiao+=".";
		reverse(xiao.begin(),xiao.end());
	}
	cout<<zheng<<xiao<<endl;
	return 0;
}