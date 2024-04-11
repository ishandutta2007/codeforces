#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[6];
string str;
int main()
{
	cin>>str;
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++)
		sum1+=str[i]-'0';
	for(int i=3;i<6;i++)
		sum2+=str[i]-'0';
	int d=max(sum1-sum2,sum2-sum1);
	if(sum1>sum2)
	{
		for(int i=0;i<3;i++)
			a[i]=str[i]-'0';
		for(int i=3;i<6;i++)
			a[i]='9'-str[i];
	}
	else
	{
		for(int i=0;i<3;i++)
			a[i]='9'-str[i];
		for(int i=3;i<6;i++)
			a[i]=str[i]-'0';
	}
	int ans=0;
	sort(a,a+6);
	for(int i=5;i>=0;i--)
	{
		if(d<=0) break;
		d-=a[i];
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}