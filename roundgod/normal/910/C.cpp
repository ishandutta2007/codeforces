#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
pair<int,bool> num[10];
bool used[10];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>str[i];
	for(int i=0;i<10;i++)
	{
		num[i].F=0;
		num[i].S=true;
	}
	for(int i=0;i<n;i++)
	{
		int s=1;
		for(int j=str[i].size()-1;j>=0;j--)
		{
			if(j==0) num[str[i][j]-'a'].S=false;
			num[str[i][j]-'a'].F+=s;
			s*=10;
		}
	}
	sort(num,num+10);
	int ans=0;
	memset(used,false,sizeof(used));
	for(int i=9;i>=0;i--)
	{
		if(!used[0]&&num[i].S)
		{
			used[0]=true;
			continue;
		}
		else
		{
			for(int j=1;j<=9;j++)
				if(!used[j])
				{
					ans+=j*num[i].F;
					used[j]=true;
					break;
				}
		}
	}
	printf("%d\n",ans);
	return 0;
}