#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		if(b==d&&a+c==b)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}