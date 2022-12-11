#include<cstdio>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)
#define Rep(i) for (int i=1;i<=26;i++)
using namespace std;

const int Maxn=1e5+19;
char s[Maxn];
int n,Q,Ql,Qr,v;
int A[Maxn],set[Maxn*4],cnt[Maxn*4][27],tmp[27];

inline void Build(int x,int L,int R)
{
	if (L==R) {cnt[x][A[L]]=1;return;}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Rep(i) cnt[x][i]=cnt[Lsn][i]+cnt[Rsn][i];
}
inline void Change(int x,int L,int R) {Rep(i) cnt[x][i]=0;cnt[x][set[x]]=R-L+1;}
inline void Push_down(int x,int L,int R)
{
	if (!set[x]||L==R) return;
	set[Lsn]=set[Rsn]=set[x];
	Change(Lsn,L,Mid),Change(Rsn,Mid+1,R);
	set[x]=0;
}
inline void Update(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) {set[x]=v;Change(x,L,R);return;}
	Push_down(x,L,R);
	if (Ql<=Mid) Update(Lsn,L,Mid);
	if (Qr>Mid) Update(Rsn,Mid+1,R);
	Rep(i) cnt[x][i]=cnt[Lsn][i]+cnt[Rsn][i];
}
inline int Query(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) return cnt[x][v];
	Push_down(x,L,R);
	int tmp=0;
	if (Ql<=Mid) tmp+=Query(Lsn,L,Mid);
	if (Qr>Mid) tmp+=Query(Rsn,Mid+1,R);
	return tmp;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&Q);
	scanf("%s",s);
	for (int i=1;i<=n;i++) A[i]=s[i-1]-'a'+1;
	Build(1,1,n);
	while (Q--)
	{
		scanf("%d%d",&Ql,&Qr);
		Rep(i) v=i,tmp[i]=Query(1,1,n);
		int ttmp=0,k=-1,now=0;
		Rep(i) if (tmp[i]&1) ttmp++,k=i;
		if (ttmp>=2) continue;
		Rep(i) if (tmp[i]>1) v=i,Update(1,1,n),Ql+=tmp[i]/2,Qr-=tmp[i]/2;
		if (k!=-1) v=k,Update(1,1,n);
	}
	for (int i=1;i<=n;i++)
	{
		Ql=Qr=i;
		for (v=1;v<=26;v++) if (Query(1,1,n)==1) {putchar(v+'a'-1);break;}
	}
	puts("");
}