#include<cstdio>
#include<vector>
#include<algorithm>

#define ERROR {puts("NO");return 0;}
using namespace std;

const int Maxn=100000+19;
vector<int> A[Maxn],Even,Odd;
int n,x,tot,k,p,c0,c1;

int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		if (x&1) Odd.push_back(x);
		else Even.push_back(x);
	}
	c0=p;c1=k-p;
	if ((Odd.size()-c1)%2) ERROR;
	if (Odd.size()<c1) ERROR;
	if (Even.size()+(Odd.size()-c1)/2<c0) ERROR;
	if (p>0)
	{
		for (;p&&Even.size();) 
			p--,A[++tot].push_back(Even[Even.size()-1]),Even.pop_back();
		while (Even.size()) A[tot].push_back(Even[Even.size()-1]),Even.pop_back();
		while (p) 
		{
			tot++;
			A[tot].push_back(Odd[Odd.size()-1]),
			Odd.pop_back();
			A[tot].push_back(Odd[Odd.size()-1]),
			Odd.pop_back();
			p--;
		}
		while (Odd.size()>c1)
		{
			A[tot].push_back(Odd[Odd.size()-1]),
			Odd.pop_back();
			A[tot].push_back(Odd[Odd.size()-1]),
			Odd.pop_back();
		}
		for (int i=0;i<c1;i++) A[++tot].push_back(Odd[Odd.size()-1]),Odd.pop_back();
	} else
	{
		for (int i=0;i<k-p;i++) A[++tot].push_back(Odd[Odd.size()-1]),Odd.pop_back();
		while (Odd.size()) A[tot].push_back(Odd[Odd.size()-1]),Odd.pop_back();
		while (Even.size()) A[tot].push_back(Even[Even.size()-1]),Even.pop_back();
	}
	puts("YES");
	for (int i=1;i<=tot;i++)
	{
		printf("%d ",A[i].size());
		for (int j=0;j<A[i].size();j++) printf("%d ",A[i][j]);puts("");
	}
}