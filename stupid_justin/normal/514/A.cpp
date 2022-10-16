#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	for (int i=0;i<str.length();++i)
	{
		
		if (str[i]<'5' || (str[i]=='9' && i==0)) cout<<str[i];
		else cout<<char(int('0')+int('9')-int(str[i]));
	}
}