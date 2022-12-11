#include<cstdio>
using namespace std;

const int Maxn=1<<17;
int Q[Maxn],De[Maxn],Xor[Maxn];
int X[Maxn],Y[Maxn];
int n,m,f,w,cnt;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d%d",&De[i],&Xor[i]);
		if (De[i]==1) Q[++f]=i;
	}
	while (f>w)
	{
		int x=Q[++w];
		if (De[x]==0) continue;
		X[cnt]=x,Y[cnt]=Xor[x],cnt++;
		Xor[Xor[x]]^=x;if (--De[Xor[x]]==1) Q[++f]=Xor[x];
	}
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d %d\n",X[i],Y[i]);
}