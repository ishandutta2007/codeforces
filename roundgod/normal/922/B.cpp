#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((i^j)>=j&&(i^j)<i+j&&(i^j)<=n) cnt++;
	printf("%d\n",cnt);
	return 0;
}