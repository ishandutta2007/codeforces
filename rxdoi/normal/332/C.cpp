#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
struct note {int A,B,num;} A[Maxn];
int n,p,k,u,use[Maxn];

inline int cmp1(note x,note y) {return x.B>y.B||x.B==y.B&&x.A<y.A;}
inline int cmp2(note x,note y) {return x.A>y.A||x.A==y.A&&x.B>y.B;}
inline int cmp3(note x,note y) 
{
	return x.B>y.B || x.B==y.B&&x.A<y.A 
		|| x.B==y.B&&x.A==y.A&&use[x.num]>use[y.num];
}

int main()
{
	scanf("%d%d%d",&n,&p,&k);u=n;
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].A,&A[i].B),A[i].num=i;
	sort(A+1,A+n+1,cmp1);
	sort(A+1,A+n-(p-k)+1,cmp2);
	for (int i=1;i<=k;i++) printf("%d ",A[i].num),use[A[i].num]=1;
	sort(A+1,A+n+1,cmp3);
	while (!use[A[u].num]) u--;
	for (int i=u+1;i<=u+p-k;i++) printf("%d ",A[i].num);
}