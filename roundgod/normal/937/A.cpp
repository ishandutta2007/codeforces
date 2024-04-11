#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt;
bool used[MAXN];
int main()
{
	memset(used,false,sizeof(used));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==0||used[x]) continue;
		cnt++;
		used[x]=true;
	}
	printf("%d\n",cnt);
	return 0;
}