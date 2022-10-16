#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[1111111];
int val[1111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>(s+1);
		n=strlen(s+1);
		memset(val,0,sizeof(int)*(n+5));
		int cur=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='+')cur++;
			else cur--;
			if(cur<0&&val[-cur]==0)val[-cur]=1,ans+=i;
//			cerr<<i<<' '<<cur<<' '<<ans<<endl;
		}
		ans+=n;
		cout<<ans<<endl;
	}
	return 0;
}