#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>str;
		int ans=0;
		for(int i=1;i<n;i++)
		{
			if(str[i]=='0')
			{
				if(str[i-1]=='0') ans+=2;
				else if(i>=2&&str[i-2]=='0') ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}