#include<bits/stdc++.h>
#define MAXN 100005
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
		cin>>str;
		int cnt0=0,cnt1=0;
		for(int i=0;i<(int)str.size();i++) if(str[i]=='0') cnt0++; else cnt1++;
		if(cnt0==cnt1) printf("%d\n",cnt0-1); else printf("%d\n",min(cnt0,cnt1));
	}
	return 0;
}