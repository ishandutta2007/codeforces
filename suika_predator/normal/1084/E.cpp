#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	string s,t;
	cin>>n>>k;
	cin>>s>>t;
	long long ans=0;
	int cur=1;
	for(int i=0;i<n;i++)
	{
		cur=cur*2;
		if(s[i]=='b')cur--;
		if(t[i]=='a')cur--;
		cur=min(cur,1000000000);
		ans+=min(cur,k);
	}
	cout<<ans<<endl;
	return 0;
}