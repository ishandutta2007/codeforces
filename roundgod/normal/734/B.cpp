#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c,d,ans;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int k=min(min(a,c),d);
	ans+=k*256;
	a-=k;c-=k;d-=k;
	k=min(a,b);
	ans+=k*32;
	printf("%d\n",ans);
	return 0;
}