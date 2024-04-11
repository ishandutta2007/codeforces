#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
LL A[Maxn],pre,suc[Maxn],x,Ans;
int n;

struct trie_tree
{
	int son[Maxn*41][2],cnt;
	
	inline void insert(LL num)
	{
		int x=0;
		for (int i=40;i>=0;i--)
		{
			int y=(num>>i)&1;
			if (!son[x][y]) son[x][y]=++cnt;
			x=son[x][y];
		}
	}
	inline LL calc(LL num)
	{
		LL Ans=0;int x=0;
		for (int i=40;i>=0;i--)
		{
			int y=((num>>i)&1)^1;
			if (son[x][y]) Ans+=1LL<<i;else y^=1;
			x=son[x][y];
		}
		return Ans;
	}
	
} trie;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]),Ans=max(Ans,A[i]);
	for (int i=n;i>=1;i--) suc[i]=suc[i+1]^A[i];
	trie.insert(x=0);
	for (int i=1;i<=n+1;i++)
	{
		Ans=max(Ans,trie.calc(suc[i]));
		x^=A[i];
		trie.insert(x);
	}
	printf("%I64d\n",Ans);
}