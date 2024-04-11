#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>str;
		int cnt0=0,cnt1=0;
		for(int i=0;i<n;i++) if(str[i]=='0') cnt0++; else cnt1++;
		if(cnt0>=2||cnt1>=2) puts("NO"); else puts("YES");
	}
	return 0;
}