#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e5+19;
typedef long long LL;
LL Min[N*4],Add[N*4],key[N],Qv;
int A[N],B[N],vis[N],tmp[N],n,Ql,Qr,Qx;
vector<int> V;

void Build(int x,int L,int R)
{
	Add[x]=0;
	if (L==R) {Min[x]=key[L];return;}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Min[x]=min(Min[Lsn],Min[Rsn]);
}
void SetAdd(int x,LL v) {Min[x]+=v,Add[x]+=v;}
void Push(int x,int L,int R)
{
	if (!Add[x]||L==R) return;
	SetAdd(Lsn,Add[x]),SetAdd(Rsn,Add[x]);Add[x]=0;
}
LL Query(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) return Min[x];
	Push(x,L,R);
	LL res=1LL<<60;
	if (Ql<=Mid) res=min(res,Query(Lsn,L,Mid));
	if (Qr>Mid) res=min(res,Query(Rsn,Mid+1,R));
	return res;
}
void Update(int x,int L,int R)
{
	Push(x,L,R);
	if (L==R) {Min[x]=Qv;return;}
	Qx<=Mid?Update(Lsn,L,Mid):Update(Rsn,Mid+1,R);
	Min[x]=min(Min[Lsn],Min[Rsn]);
}
void Change(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) {SetAdd(x,Qv);return;}
	if (Ql<=Mid) Change(Lsn,L,Mid);
	if (Qr>Mid) Change(Rsn,Mid+1,R);
	Min[x]=min(Min[Lsn],Min[Rsn]);
}

void Solve(int f)
{
	For(i,1,n) A[i+n]=A[i],B[i+n]=B[i];
	For(i,1,2*n) key[i]=key[i-1]+A[i]-B[i];
	Build(1,1,2*n-1);
	For(i,1,n+1)
	{
		Ql=i,Qr=i+n-1;
		if (Query(1,1,2*n-1)>=0) vis[!f?i:n-i+1]=1;
		if (i==n) break;
		Qx=i+n,Qv=key[i+n]-key[i],Update(1,1,2*n-1);
		Ql=i+1,Qr=i+n-1,Qv=-(A[i]-B[i]),Change(1,1,2*n-1);
	}
}

int main()
{
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();

	Solve(0);
	reverse(A+1,A+n+1);
	reverse(B+1,B+n);
	Solve(1);

	For(i,1,n+1) if (vis[i]) V.Pb(i);
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}