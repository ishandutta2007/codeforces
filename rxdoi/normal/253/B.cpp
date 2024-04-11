#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
int n,c[Maxn],pre[Maxn],suc[Maxn],Ans,tmp;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&c[i]),pre[c[i]]++,suc[c[i]]++;
	for (int i=1;i<=5000;i++) pre[i]+=pre[i-1];
	for (int i=5000;i;i--) suc[i]+=suc[i+1];
	Ans=(1<<30)-1;
	for (int i=0;i<n;i++)
		Ans=min(Ans,pre[c[i]/2-(c[i]%2==0)]+suc[c[i]+1]);
	printf("%d\n",Ans);
}