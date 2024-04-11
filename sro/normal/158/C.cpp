#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <fstream>
#include <ctime>
#include <list>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <cstring>
using namespace std;

vector<string> ss;

inline void pwd()
{
	for(int i=0;i<ss.size();i++)
		cout<<"/"<<ss[i];
	cout<<"/"<<endl;
}

string cds;
inline void cd()
{
	cin>>cds;
	cds+="/";
	bool xgs=0;
	if(cds[0]=='/')ss.resize(0),xgs=1;
	for(int i=xgs;1;)
	{
		if(cds.find("..",i)==i)
		{
			ss.pop_back();
			i+=3;
		}
		else
		{
			string _s=cds.substr(i,cds.find("/",i)-i);
			i=cds.find("/",i)+1;
			ss.push_back(_s);
		}
		if(i==cds.size())break;
	}
}

int n;
string a;

int main()
{
	//freopen("tongyonginput.in","r",stdin);
	//freopen("tongyongoutput.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a,a=="cd"?cd():pwd();
	return 0;
}