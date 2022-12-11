#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)
using namespace std;

const int N=1e5+19,oo=(1<<30)-1;
struct Point {int x,y,DDx;} A[N];
int n,x;
int Dx[N],Dy[N],Sx[N],Sy[N],tx,ty;
int s[10],cnt[10];
int yl,yr,Ql,Qr,t,v;
map<int,int> Mx,My;
vector<int> V[N*4];

inline int cmpx(Point A,Point B) {return A.x<B.x;}
inline int cmpy(Point A,Point B) {return A.y>B.y;}

inline int Query(int x,int L,int R)
{
	if (Ql<=L&&R<=Qr) 
	{
		int hi=lower_bound(V[x].begin(),V[x].end(),yr)-V[x].begin();
		int lo=lower_bound(V[x].begin(),V[x].end(),yl)-V[x].begin();
		int _1=V[x][0],_2=V[x][1],_3=V[x][2];
		return hi-lo;
	}
	int tmp=0;
	if (Ql<=Mid) tmp+=Query(Lsn,L,Mid);
	if (Qr>Mid) tmp+=Query(Rsn,Mid+1,R);
	return tmp;
}
inline void Update(int x,int L,int R)
{
	V[x].push_back(v);
	if (L==R) return;
	if (t<=Mid) Update(Lsn,L,Mid);else Update(Rsn,Mid+1,R);
}
inline int Que(int L,int R) {Ql=L,Qr=R;return Query(1,1,tx);}
inline void Upd(int x,int y) {t=x,v=y;Update(1,1,tx);}

inline void check()
{
	int X1=s[1]+s[4]+s[7],X2=X1+s[2]+s[5]+s[8];
	if (!Mx[X1]||!Mx[X2]) return;X1=Mx[X1],X2=Mx[X2];
	int Y1=s[1]+s[2]+s[3],Y2=Y1+s[4]+s[5]+s[6];
	if (!My[Y1]||!My[Y2]) return;Y1=Dy[My[Y1]];Y2=Dy[My[Y2]];
	
	yl=Y1;yr=oo;cnt[1]=Que(1,X1);cnt[2]=Que(X1+1,X2);
	yl=Y2;yr=Y1;cnt[4]=Que(1,X1);cnt[5]=Que(X1+1,X2);
	
	if (cnt[1]!=s[1]||cnt[2]!=s[2]||cnt[4]!=s[4]||cnt[5]!=s[5]) return;
	printf("%.10lf %.10lf\n",Dx[X1]+0.5,Dx[X2]+0.5);
	printf("%.10lf %.10lf\n",Y1-0.5,Y2-0.5);
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].x,&A[i].y);
	
	sort(A+1,A+n+1,cmpx);
	for (int i=1;i<=n;i++) {if (i==1||A[i].x!=A[i-1].x) tx++,Dx[tx]=A[i].x;Sx[tx]++;A[i].DDx=tx;}
	for (int i=1;i<=n;i++) Sx[i]+=Sx[i-1],Mx[Sx[i]]=i;
	sort(A+1,A+n+1,cmpy);
	for (int i=1;i<=n;i++) {if (i==1||A[i].y!=A[i-1].y) ty++,Dy[ty]=A[i].y;Sy[ty]++;}
	for (int i=1;i<=n;i++) Sy[i]+=Sy[i-1],My[Sy[i]]=i;
	for (int i=n;i>=1;i--) Upd(A[i].DDx,A[i].y);
	
	for (int i=1;i<=9;i++) scanf("%d",&s[i]);
	sort(s+1,s+10);
	do check(); while (next_permutation(s+1,s+10));
	puts("-1");
}