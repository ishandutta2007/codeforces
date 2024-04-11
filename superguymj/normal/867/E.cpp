#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<queue>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,x;
long long ans;
priority_queue <int> q;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&x),q.push(-x),q.push(-x),ans+=q.top()+x,q.pop();
	printf("%I64d\n",ans);
	return 0;
}