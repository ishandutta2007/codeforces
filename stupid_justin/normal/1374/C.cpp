#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
long long a[N],sum[N];
bool cmp (int x,int y)
{
	return x>y;
}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int cnt,ans;
		cnt=ans=0;
		for (int i=1;i<=n;i++)
		{
			char ch;
			cin>>ch;
			if (ch=='(') cnt++; 
			if (ch==')') cnt--;
			ans=min(ans,cnt);
//			printf("for %d ans=%d\n",i,ans);
		}
		cout<<ans*-1<<endl;
	}
}