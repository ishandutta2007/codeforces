#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[50000];

bool pk(string s,string t)
{
	return s+t<t+s;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	sort(a,a+n,pk);
	for(int i=0;i<n;i++)
		cout<<a[i];
	
	return 0;
	//So easy?
	//.
	//?????.SRKI .
}