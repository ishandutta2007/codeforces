#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
struct Exam
{
	int A,B;
	bool operator < (const Exam& aa) const {return B<aa.B;}
} A[Maxn];
int n,r,tmp;
LL Ans,Avg;

int main()
{
	scanf("%d%d%d",&n,&r,&tmp);
	for (int i=0;i<n;i++) scanf("%d%d",&A[i].A,&A[i].B),Avg+=tmp-A[i].A;
	sort(A,A+n);
	for (int i=0;i<n&&Avg>0;i++)
		if (r-A[i].A>=Avg) Ans+=1LL*Avg*A[i].B,Avg=0;
			else Ans+=1LL*(r-A[i].A)*A[i].B,Avg-=r-A[i].A;
	printf("%I64d\n",Ans);
}