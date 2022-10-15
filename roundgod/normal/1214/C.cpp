#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[MAXN];
int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	int minx=0;
	for(int i=1;i<=n;i++) 
	{
		if(str[i]=='(') a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
		minx=min(minx,a[i]);
	}
	if(a[n]==0&&minx>=-1) puts("Yes"); else puts("No");
    return 0;
}