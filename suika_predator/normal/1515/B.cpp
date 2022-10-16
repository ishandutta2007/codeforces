#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
set<long long> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	for(long long i=1;i<=40000;i++)
	{
		s.insert(i*i*2);
		s.insert(i*i*4);
	}
	while(T--)
	{
		cin>>n;
		if(s.find(n)!=s.end())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}