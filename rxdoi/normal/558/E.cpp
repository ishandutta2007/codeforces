#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19;
char s[N];
int C[26],n,Q,L,R,k,Ql,Qr,Qv;

//SegTree
struct Seg
{
	#define Lsn (x<<1)
	#define Rsn (x<<1|1)
	#define Mid (L+R>>1)

	int Sum[N*4],Set[N*4],ch;
	
	void SetS(int x,int L,int R,int v) {Set[x]=v,Sum[x]=v*(R-L+1);}
	void Down(int x,int L,int R)
	{
		if (~Set[x]) SetS(Lsn,L,Mid,Set[x]),SetS(Rsn,Mid+1,R,Set[x]),Set[x]=-1;
	}
	void Build(int x,int L,int R)
	{
		Set[x]=-1;
		if (L==R) {Sum[x]=s[L]==ch+'a';return;}
		Build(Lsn,L,Mid);Build(Rsn,Mid+1,R);
		Sum[x]=Sum[Lsn]+Sum[Rsn];
	}
	void Update(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) {SetS(x,L,R,Qv);return;}
		Down(x,L,R);
		if (Ql<=Mid) Update(Lsn,L,Mid);
		if (Qr>Mid) Update(Rsn,Mid+1,R);
		Sum[x]=Sum[Lsn]+Sum[Rsn];
	}
	int Query(int x,int L,int R)
	{
		if (Ql<=L&&R<=Qr) return Sum[x];
		Down(x,L,R);
		int res=0;
		if (Ql<=Mid) res+=Query(Lsn,L,Mid);
		if (Qr>Mid) res+=Query(Rsn,Mid+1,R);
		return res;
	}
	void DFS(int x,int L,int R)
	{
		if (L==R) {if (Sum[x]) s[L]=ch+'a';return;}
		Down(x,L,R);
		DFS(Lsn,L,Mid);DFS(Rsn,Mid+1,R);
	}
} S[26];

int main()
{
	n=IN(),Q=IN();
	scanf("%s",s+1);n=strlen(s+1);
	For(i,0,26) S[i].ch=i,S[i].Build(1,1,n);
	while (Q--)
	{
		Ql=IN(),Qr=IN(),k=IN();
		For(i,0,26) C[i]=S[i].Query(1,1,n);
		For(i,0,26) Qv=0,S[i].Update(1,1,n);
		if (k)
			for (int i=0,_=Ql;i<26;_+=C[i++])
			{
				Ql=_,Qr=_+C[i]-1,Qv=1;
				if (Ql<=Qr) S[i].Update(1,1,n);
			}
		else
			for (int i=25,_=Ql;~i;_+=C[i--])
			{
				Ql=_,Qr=_+C[i]-1,Qv=1;
				if (Ql<=Qr) S[i].Update(1,1,n);
			}
	}
	For(i,0,26) S[i].DFS(1,1,n);
	puts(s+1);
}