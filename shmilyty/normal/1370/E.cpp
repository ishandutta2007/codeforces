#include<bits/stdc++.h>
using namespace std;
int n,cnt1,cnt2,ans;
string a,b;
int main()
{
	scanf("%d",&n);
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='1'&&b[i]=='0')
			cnt1--;
		if(a[i]=='0'&&b[i]=='1')
			cnt1++;
	}
	if(cnt1!=0)
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='1'&&b[i]=='0')
		{
			cnt1++;
			ans=max(ans,cnt1);
			cnt2--;
			cnt2=max(cnt2,0);
		}
		if(a[i]=='0'&&b[i]=='1')
		{
			cnt2++;
			ans=max(ans,cnt2);
			cnt1--;
			cnt1=max(cnt1,0);
		}
	}
	cout<<ans;
	return 0;
}