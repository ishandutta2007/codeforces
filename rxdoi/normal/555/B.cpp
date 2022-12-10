#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=2e5+19;
typedef long long LL;
struct Seg
{
	LL L,R;int ID;
	bool operator < (const Seg& B) const {return R>B.R;}
} S[N];
struct Bri
{
	LL x;int ID;
	bool operator < (const Bri& B) const {return x<B.x;}
} D[N];
priority_queue<Seg> Q;
struct Island {LL L,R;} I[N];
int Ans[N],n,m,c=1;

bool cmpS(Seg A,Seg B) {return A.L<B.L;}

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) scanf("%I64d%I64d",&I[i].L,&I[i].R);
	For(i,1,m+1) scanf("%I64d",&D[i].x),D[i].ID=i;
	For(i,1,n) S[i]=(Seg){I[i+1].L-I[i].R,I[i+1].R-I[i].L,i};n--;
	sort(S+1,S+n+1,cmpS);
	sort(D+1,D+m+1);
	For(i,1,m+1)
	{
		while (c<=n&&S[c].L<=D[i].x) Q.push(S[c++]);
		if (Q.empty()) continue;
		Seg Sx=Q.top();Q.pop();
		if (Sx.R<D[i].x) return puts("No"),0;
		Ans[Sx.ID]=D[i].ID;
	}
	if (c!=n+1||!Q.empty()) return puts("No"),0;
	puts("Yes");
	For(i,1,n+1) printf("%d ",Ans[i]);
}