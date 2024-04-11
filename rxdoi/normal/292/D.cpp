#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500+19,M=10000+19;
struct Edge {int x,y;} E[M];
int n,Q,L,R,m;

struct Set
{
    int Fa[N];
    Set() {For(i,1,N) Fa[i]=i;}
    int Num()
    {
        int cnt=0;
        For(i,1,n+1) cnt+=(Fa[i]==i);
        return cnt;
    }
    int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
    void Union(int x,int y)
    {
        int fx=Getf(x),fy=Getf(y);
        if (fx!=fy) Fa[fx]=fy;
    }
} P[M],S[M],A;

Set Merge(Set A,Set B)
{
    Set C=A;
    For(i,1,n+1) C.Union(i,B.Fa[i]);
    return C;
}

int main()
{
    n=IN(),m=IN();
    For(i,1,m+1) E[i]=(Edge){IN(),IN()};
    for (int i=1;i<=m;i++) P[i]=P[i-1],P[i].Union(E[i].x,E[i].y);
    for (int i=m;i>=1;i--) S[i]=S[i+1],S[i].Union(E[i].x,E[i].y);
    Q=IN();
    while (Q--) L=IN(),R=IN(),printf("%d\n",Merge(P[L-1],S[R+1]).Num());
}