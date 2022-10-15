#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
using namespace std;
int k,a,b;
int main()
{
	scanf("%d%d%d",&k,&a,&b);
	if((a>=k&&b>=k)||(a>=k&&a%k==0)||(b>=k&&b%k==0)) printf("%I64d\n",(ll)a/k+(ll)b/k); else puts("-1");
	return 0;
}