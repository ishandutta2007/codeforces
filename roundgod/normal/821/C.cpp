#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int st[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	int t=0,flag=0,cnt=0,removed=0;
	for(int i=0;i<2*n;i++)
	{
		cin>>str;
		int x;
		if(str[0]=='a')
		{
			scanf("%d",&x);
			st[t++]=x;
		}
		else
		{
			//printf("%d %d\n",st[t-1],removed+1);
			if(t<=flag||st[t-1]==removed+1)
			{
				t--;
				flag=min(flag,t);
			}
			else
			{
				cnt++;
				t--;
				flag=t;
			}
			removed++;
		}
		//printf("%d\n",cnt);
	}
	printf("%d\n",cnt);
	return 0;
}