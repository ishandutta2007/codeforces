#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int main()
{
	scanf("%I64d",&n);
	if(n==0) {puts("0"); return 0;}
	if(n&1) printf("%I64d\n",(n+1)/2); else printf("%I64d\n",n+1);
	return 0;
}