#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int main()
{
	string str;
	cin>>str;
	int len=str.length();
//	cout<<len<<endl;
	int flag=0;
	for (int i=1;i<len;i++)
	{
		if (str[i]=='1') flag=1;
	}
	int ans=(len+1)/2;
	if (len%2==1 && !flag) ans--;
	cout<<ans<<endl;
}