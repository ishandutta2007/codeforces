/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,a,b,t[N];
vector <int> ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void solve(int A,int B)
{
	for (int i=0;i<=a;i++)
	{
		int j=a-i,k=A-i,p=B-j;
		if (k<0||p<0) continue;
		t[j+k]=1;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		a=read();b=read();
		int n=a+b;
		for (int i=0;i<=n;i++) t[i]=0;
		if (n&1) solve(n/2,n/2+1),solve(n/2+1,n/2);
		else solve(n/2,n/2);
		int w=0;
		for (int i=0;i<=n;i++) if (t[i]) w++;
		printf("%d\n",w);
		for (int i=0;i<=n;i++) if (t[i]) printf("%d ",i);
		printf("\n");
	}
}