#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[100010][30],b[30],ans;
bool judge(int l,int r)
{
	if(l<0)
		return 0;
	for(int i=0;i<26;i++)
		if(a[r][i]-a[l][i]>b[i])
			return 0;
	return 1;
}
int main()
{
	cin>>s>>t;
	for(int i=0;i<t.size();i++)
		b[t[i]-'a']++;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<26;j++)
			a[i+1][j]+=a[i][j]+(s[i]=='a'+j);
		ans+=judge(i+1-t.size(),i+1);
	}
	cout<<ans;
	return 0;	
}