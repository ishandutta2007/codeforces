#include<cstdio>
#include<algorithm>
using namespace std;

const int M=1e5+19;
int n,m,s,f,rev,now=1,L[M],R[M],t[M];

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&f);
	if (s>f) swap(s,f),rev=1;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&t[i],&L[i],&R[i]);
		R[i]=min(R[i],f);L[i]=max(L[i],s);
		if (rev) L[i]=s+f-L[i],R[i]=s+f-R[i],swap(L[i],R[i]);
	}
	for (int i=0;s<f;now++)
	{
		while (i<m&&(t[i]<now||(t[i]==now&&(s>R[i]||s+1<L[i])))) i++;
		if (t[i]==now&&s+1>=L[i]&&s<=R[i]) 
			{putchar('X');continue;}
		s++;
		putchar(rev?'L':'R');
	}
}