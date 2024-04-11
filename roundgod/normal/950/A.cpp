#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) swap(a,b);
	if(a+c<=b) printf("%d\n",2*(a+c));
	else printf("%d\n",(a+b+c)-((a+b+c)&1));
	return 0;
}