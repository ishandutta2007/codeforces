#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,r,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&r,&b);
		for(int i=0;i<b+1;i++)
		{
			for(int j=0;j<(r+i)/(b+1);j++) printf("R");
			if(i!=b) printf("B");
		}
		puts("");
	}
	return 0;
}