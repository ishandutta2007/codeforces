#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
typedef long long LL;
const LL oo=(1LL<<60)-1;
struct note {int ai,x,y,ID;} D[Maxn];
int n;
LL F[Maxn],d;

inline int Dis(note A,note B) {return abs(A.x-B.x)+abs(A.y-B.y);}
inline int cmp(note A,note B) {return Dis(A,D[n])>Dis(B,D[n]);}

int main()
{
	scanf("%d%I64d",&n,&d);
	for (int i=2;i<n;i++) scanf("%d",&D[i].ai);
	for (int i=1;i<=n;i++) scanf("%d%d",&D[i].x,&D[i].y),D[i].ID=i;
	sort(D+2,D+n,cmp);
	for (int i=n;i>=1;i--)
	{
		if (i!=n) F[i]=oo;
		for (int j=i+1;j<=n;j++) F[i]=min(F[i],F[j]+1LL*d*Dis(D[i],D[j])-D[i].ai);
		if (D[i].ID==1) {printf("%d\n",F[i]);return 0;}
	}
}