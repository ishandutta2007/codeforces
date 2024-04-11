#include<bits/stdc++.h>
using namespace std;
int n;
int x;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>x;
	set<int> s;
	while(n)
	{
		if(s.find(n%x)!=s.end())
		{
			cout<<"NO"<<endl;
			return 0;
		}
		s.insert(n%x);
		n/=x;
	}
	cout<<"YES"<<endl;
	return 0;
}