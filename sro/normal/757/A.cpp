#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

map<char,int> havezm;
int least=123456789,i;
const char st[10]="Bulbasaur";
string s;

int main()
{
	cin>>s;
	for(i=0;i<s.size();i++)havezm[s[i]]++;
	cout<<min(havezm['B'],min(havezm['u']/2,min(havezm['l'],min(havezm['b'],min(havezm['a']/2,min(havezm['s'],havezm['r']))))));
	return 0;
}