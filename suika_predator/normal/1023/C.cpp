#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	string s;
	cin>>n>>k>>s;
	vector<int> cnt(n+5);
	for(int i=n-1;i>=0;i--)
	{
		cnt[i]=cnt[i+1]+(s[i]==')');
	}
	string ans;
	int cur=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(' and cur+1<=min(cnt[i+1],k-(int)ans.length()))
		{
			ans.push_back('(');
			cur++;
		}
		else if(s[i]==')' and cur>0)
		{
			ans.push_back(')');
			cur--;
		}
	}
	cout<<ans<<endl;
	return 0;
}