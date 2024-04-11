#include<cstdio>
#include<queue>
using namespace std;

int x,n,m;
struct child {int num,Dis;};
queue<child> Q;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&x),Q.push((child){x,i+1});
	while (!Q.empty())
	{
		child x=Q.front();Q.pop();
		if (x.num-m>0) Q.push((child){x.num-m,x.Dis});
		if (Q.empty()) printf("%d\n",x.Dis);
	}
}