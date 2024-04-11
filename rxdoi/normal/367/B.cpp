#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int Maxn=4e5+19;
map<int,int> Map;
int n,m,p,cnt[Maxn],tar[Maxn],Ans,tot,_tot;
int A[Maxn],B[Maxn],sol[Maxn];

inline int get(int x) {int &y=Map[x];return y?y:y=++tot;}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]=get(A[i]);
	for (int i=1;i<=m;i++) scanf("%d",&B[i]),B[i]=get(B[i]),tar[B[i]]++;
	_tot=0;
	for (int i=1;i<=n+m;i++) if (tar[i]) _tot++;
	for (int i=1;i<=p;i++)
	{
		int tmp=0;
		for (int j=i;j<=n;j+=p)
		{
			if ((j-i)/p+1>m) 
				if (cnt[A[j-p*m]]--==tar[A[j-p*m]]&&tar[A[j-p*m]]) tmp--;
			if (++cnt[A[j]]==tar[A[j]]&&tar[A[j]]) tmp++;
			if (tmp==_tot) sol[Ans++]=j-p*(m-1); 
		}
		for (int j=i;j<=n;j+=p) cnt[A[j]]=0;
	}
	printf("%d\n",Ans);
	sort(sol,sol+Ans);
	for (int i=0;i<Ans;i++) printf("%d ",sol[i]);puts("");
}