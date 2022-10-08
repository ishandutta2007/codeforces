#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string S="";int T=-1000000007;
	int _;scanf("%d",&_);
	while(_--)
	{
		string s;int a,b,c,d,e,f,g;
		cin>>s>>a>>b>>c>>d>>e>>f>>g;
		if(T<100*a-50*b+c+d+e+f+g)T=100*a-50*b+c+d+e+f+g,S=s;
	}
	cout<<S<<endl;
	return 0;
}