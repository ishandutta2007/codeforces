#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int cnt=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='x') cnt++; else cnt=0;
		if(cnt>=3) ans++;
	}
	printf("%d\n",ans);
	return 0;
}