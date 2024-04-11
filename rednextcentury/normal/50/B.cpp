#include<bits/stdc++.h>
using namespace std;
long long num[1000000];
int main()
{
  string s;
  cin>>s;
  long long ret=0;
  for (int i=0;i<s.size();i++)
	num[s[i]]++,ret+=num[s[i]]*2-1;
  cout<<ret<<endl;
}