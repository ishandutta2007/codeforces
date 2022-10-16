#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,cnt;
string s;
map<int,int> num;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		cin>>s;
		cnt=ans=0;
		num.clear();
		for(int i=0;i<s.size();i++)
		{
			int a=s[i]-'1';
			cnt+=a;
//			cout<<a<<endl;
			if(cnt==0)
				ans++;
			ans+=num[cnt];
			num[cnt]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}