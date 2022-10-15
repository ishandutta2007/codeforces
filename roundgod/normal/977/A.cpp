#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	while(k)
	{
		if(n%10==0) n/=10; else n--;
		k--;
	}
	printf("%d\n",n);
	return 0;
}