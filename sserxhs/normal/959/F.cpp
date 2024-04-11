#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2,M=30,p=1e9+7;
int ji[N][M],len[N],mi[N];
int n,q,i,x,y,j;
inline void read(register int &x)
{
	register int c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	read(n);read(q);mi[0]=1;
	for (i=1;i<=n;i++)
	{
		read(x);len[i]=len[i-1];if ((mi[i]=mi[i-1]<<1)>=p) mi[i]-=p;
		memcpy(ji[i],ji[i-1],sizeof(ji[i]));
		for (j=29;x;j--) if (1<<j&x)
		{
			if (!ji[i][j]) ji[i][j]=x,++len[i];x^=ji[i][j];
		}
	}
	while (q--)
	{
		read(y);read(x);
		for (i=29;x;i--) if (1<<i&x)
		{
			if (!ji[y][i]) {x=-1;break;}x^=ji[y][i];
		}
		printf("%d\n",~x?mi[y-len[y]]:0);
	}
}