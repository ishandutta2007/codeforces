#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		int a=0,b=0;
		for(auto ch:s)
		{
			if(ch=='0')a++;
			else b++;
		}
		if(a>1 or b>1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	return 0;
}