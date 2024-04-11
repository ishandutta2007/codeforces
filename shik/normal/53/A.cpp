// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define N 110
using namespace std;
string s,t[N];
int main()
{
	int n;
	cin>>s>>n;
	for ( int i=0; i<n; i++ ) cin>>t[i];
	sort(t,t+n);
	string x=*lower_bound(t,t+n,s);
	if ( x.substr(0,s.size())==s ) cout<<x<<endl;
	else cout<<s<<endl;
	return 0;
}