#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	int n=s.length();
	for(int i=2;i<n;i++)
	{
		if(s[i]-'A'!=(s[i-1]-'A'+s[i-2]-'A')%26)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}