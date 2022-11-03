#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s[524288];
int n,j;

int main()
{
	cin>>n;getline(cin,s[0]);
	for(int i=0;i<n;i++)getline(cin,s[i]);
	for(int i=n-2;i>=0;i--)
		if(s[i]>s[i+1])
		{
			for(j=0;j<s[i].size()&&s[i][j]<=s[i+1][j];j++);
			s[i].resize(j);
		}
	for(int i=0;i<n;i++)cout<<s[i]<<endl;
	return 0;
}