#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<queue>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=105;
int T,n,a[N];
priority_queue <int> que;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),que.push(a[i]);
		int tmp,lst=0;
		for(tmp=0; !que.empty(); tmp^=1)
		{
			int nw=que.top(); que.pop();
			if(lst) que.push(lst);
			lst=nw-1;
		}
		if(tmp) puts("T");
		else puts("HL");
	}
	return 0;
}