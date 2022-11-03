#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

bool mark[1000];
int n,K,c;

int main()
{
	scanf("%d%d",&n,&K);
	scanf("%d",&c);
	memset(mark,false,sizeof(mark));
	for (int i=0;i<c;++i)
	{
		int x;
		scanf("%d",&x);
		mark[x]=true;
	}
	int cnt=0,last=0;
	for (int i=1;i<=n;++i)
	{
		if (mark[i]) last=i,++cnt;
		else if (i==last+K)
		{
			mark[i]=true;
			last=i;
			++cnt;
		}
	}
	printf("%d\n",cnt);
	
	return 0;
}