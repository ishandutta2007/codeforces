#include<bits/stdc++.h>
using namespace std;
int maxx;
string s,ans;
map<string,int> num;
map<string,string> month;
void init()
{
	month["01"]="31";
	month["02"]="28";
	month["03"]="31";
	month["04"]="30";
	month["05"]="31";
	month["06"]="30";
	month["07"]="31";
	month["08"]="31";
	month["09"]="30";
	month["10"]="31";
	month["11"]="30";
	month["12"]="31";
}
void solve(string x)
{
	string d,m,y; 
	for(int i=0;i<x.size();i++)
	{
		if(i==2||i==5)
		{ 
			if(x[i]!='-')
				return ;
		} 
		else
		{
			if(x[i]=='-')
				return ;
		}
	}	
	d=x.substr(0,2);
	m=x.substr(3,2);
	y=x.substr(6,4);
	if(y>"2015"||y<"2013")
		return ;
	if(d=="00")
		return ;
	if(m>"12"||m=="00")
		return ;
	string maxd=month[m];
	if(maxd[0]>d[0]||(maxd[0]==d[0]&&maxd[1]>=d[1]))
	{
		string res=d+"-"+m+"-"+y;
		num[res]++;
		if(num[res]>maxx)
		{
			maxx=num[res];
			ans=res;
		}
	}
} 
int main()
{
	init();
	cin>>s;
	for(int i=0;i<=s.size()-10;i++)
		solve(s.substr(i,10));
	cout<<ans;
	return 0;
}