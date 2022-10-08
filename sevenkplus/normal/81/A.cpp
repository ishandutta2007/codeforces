#include<cstdio>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<char> A;string s;
int main()
{
	cin>>s;
	for(int i=0;i<(int)s.length();i++)
		if(!A.empty()&&A.back()==s[i])A.erase(A.end()-1);
		else A.push_back(s[i]);
	for(int i=0;i<(int)A.size();i++)putchar(A[i]);puts("");
	return 0;
}