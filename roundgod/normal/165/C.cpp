#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,st[MAXN];
string str;
int main()
{
	scanf("%d",&k);
	cin>>str;
	int t=0;
	int cnt=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1') {st[t++]=cnt; cnt=0;}
		else cnt++;
	}
	st[t++]=cnt;
	if(k==0)
	{
		ll ans=0;
		for(int i=0;i<t;i++) ans+=1LL*st[i]*(st[i]+1)/2;
		printf("%I64d\n",ans);
	}
	else
	{
		ll ans=0;
		for(int i=0;i+k<t;i++)
			ans+=1LL*(st[i]+1)*(st[i+k]+1);
		printf("%I64d\n",ans);
	}
	return 0;
}