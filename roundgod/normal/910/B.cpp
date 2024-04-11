#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int ans=INF;
	int num0=n/a;
	int num1=(n-b)/a;
	int num2=(n>=2*b)?(n-2*b)/a:-1;
	int num3=n/b;
	ans=min(ans,(4-1)/num0+1+(2-1)/num3+1);
	if(num2!=-1) ans=min(ans,1+(4-num2+num0-1)/num0);
	if(num1>=2) ans=min(ans,2);
	else ans=min(ans,2+(4-2*num1+num0-1)/num0);
	printf("%d\n",ans);
	return 0;
}