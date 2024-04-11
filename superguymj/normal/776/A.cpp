#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
string s,t,a,b;
int n;

int main()
{
	cin>>s>>t;
	cin>>n;
	cout<<s<<' '<<t<<endl;
	rep(i,1,n)
	{
		cin>>a>>b;
		if(a==s) s=b; else t=b;
		cout<<s<<' '<<t<<endl;
	}
	return 0;
}