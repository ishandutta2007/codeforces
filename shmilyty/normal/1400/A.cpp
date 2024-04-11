#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
void solve()
{
	string ss;
	for(int i=0;i<n;i++)
		ss+="0";
	for(int i=0;i+n<=s.size();i++)
		if(s.substr(i,n)==ss)
		{
			cout<<ss<<endl;
			return ;
		}
	for(int i=0;i<n;i++)
		ss[i]='1';
	cout<<ss<<endl;
	return ; 
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>s;
		solve();
	}	
	return 0;
}