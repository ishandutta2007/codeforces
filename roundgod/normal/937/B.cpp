#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int p,y;
bool C(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) if(i<=p) return false;
	return true;
}
int main()
{
	scanf("%d%d",&p,&y);
	for(int i=y;i>p;i--)
		if(C(i))
		{
			printf("%d\n",i);
			return 0;
		}
	puts("-1");
	return 0;
}