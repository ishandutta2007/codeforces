#include<map>
#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
map<int,int> M;
typedef map<int,int>::iterator It;
int A[N],B[N],C[2*N],S[N*2],n,t,cnt;
long long Ans;

int Query(int x) {int Ans=0;for (int i=x;i;i-=i&-i) Ans+=S[i];return Ans;}
void Update(int x) {for (int i=x;i<=t;i+=i&-i) S[i]++;}

int main()
{
	n=IN();
	For(i,1,n+1)
	{
		A[i]=IN(),B[i]=IN();
		if (!M[A[i]]) M[A[i]]=A[i];
		if (!M[B[i]]) M[B[i]]=B[i];
		swap(M[A[i]],M[B[i]]);
		C[++t]=A[i],C[++t]=B[i];
	}
	sort(C+1,C+t+1);t=unique(C+1,C+t+1)-C-1;
	for (It it=M.begin();it!=M.end();it++)
	{
		int L=it->first,R=it->second,x=lower_bound(C+1,C+t+1,R)-C;
		if (L>R) swap(L,R);
		Ans+=max(R-L-1-(lower_bound(C+1,C+t+1,R)-upper_bound(C+1,C+t+1,L)),0);
		Ans+=cnt-Query(x);cnt++;Update(x);
	}
	printf("%I64d\n",Ans);
}