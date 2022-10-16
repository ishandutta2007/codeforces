#include <cstdio>
using namespace std;
const int maxn=200005;
char m[maxn];
int len,i,j,ans;
int nex[maxn],las[maxn],sz[maxn];
struct usr_queue
{
	int q[maxn],ql,qr;
	usr_queue(){ql=1;qr=0;}
	void push(int u){q[++qr]=u;}
	void pop(){ql++;}
	int top(){return q[ql];}
	bool empty(){return ql>qr;}
};
usr_queue S0,S1;
int main()
{
	scanf("%s",m+1);
	for (len=1;m[len+1];len++);
	for (i=1;i<=len;i++)
		if (m[i]=='0')
		{
			if (S1.empty())
			{
				S0.push(i);
				sz[i]=1;
				ans++;
				continue;
			}
			j=S1.top();
			S1.pop();
			nex[j]=i;
			las[i]=j;
			sz[i]=sz[j]+1;
			S0.push(i);
		}
		else
		{
			if (S0.empty())
			{
				printf("-1\n");
				return 0;
			}
			j=S0.top();
			S0.pop();
			nex[j]=i;
			las[i]=j;
			sz[i]=sz[j]+1;
			S1.push(i);
		}
	if (!S1.empty())
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	for (i=1;i<=len;i++)
		if (nex[i]==0)
		{
			printf("%d ",sz[i]);
			j=i;
			while (las[j])
				j=las[j];
			while (j!=i)
			{
				printf("%d ",j);
				j=nex[j];
			}
			printf("%d\n",i);
		}
	return 0;
}