# include <iostream>
# include <map>
# include <string>
# include <cstdio>
# include <queue>
# include <fstream>
using namespace std;
int a[1000];
int main()
{
	int n;
	string s;
	cin>>n;
	s+="<3";
	for (int i=0;i<n;i++)
	{
		string f;
		cin>>f;
		s+=f;
		s+="<3";
	}
	string b;
	cin>>b;
	bool p=0;
	for (int i=0,x=0;i<b.length();i++)
	{
		if (b[i]==s[x])
			x++;
		if (x==s.length())
		{
			p=1;
			break;
		}
	}
	if (p==0)
		cout<<"no"<<endl;
	else
		cout<<"yes"<<endl;
}