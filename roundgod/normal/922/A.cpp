#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll x,y;
int main()
{
	scanf("%I64d%I64d",&x,&y);
	if(x+1<y||(x+y)%2==0||(x>0&&y==0)||(x>0&&y==1)) puts("No"); else puts("Yes");
	return 0;
}