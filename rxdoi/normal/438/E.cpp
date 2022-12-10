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

const int N=100000*4+19,P=998244353,I2=499122177;
int W[2][N],rev[N],C[N],A[N],F[N],A0[N],F0[N],Grev[N];
int c,n,m,x;

int Pow(int a,int b)
{
    int res=1;
    for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
    return res;
}
void Prepare(int n)
{
    int W0=Pow(3,(P-1)/n),I0=Pow(W0,P-2),Pw=1,Pi=1;
    For(i,0,n)
    {
        W[0][i]=Pw,W[1][i]=Pi,Pw=1LL*Pw*W0%P,Pi=1LL*Pi*I0%P,rev[i]=0;
        for (int x=i,&y=rev[i],k=1;k<n;k<<=1,x>>=1) y=y<<1|x&1;
    }
}
void NTT(int *A,int n,int f)
{
    For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
    for (int i=1;i<n;i<<=1)
        for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
            for (int k=j,l=0,x,y;k<j+i;k++,l+=t)
                x=A[k],y=1LL*A[k+i]*W[f][l]%P,A[k]=(x+y)%P,A[k+i]=(x-y+P)%P;
    if (f)
    {
        int In=Pow(n,P-2);
        For(i,0,n) A[i]=1LL*A[i]*In%P;
    }
}
void Getrev(int *A,int *B,int n)    //A0
{
    if (n==1) {B[0]=Pow(A[0],P-2);return;}
    Getrev(A,B,(n+1)/2);
    for (c=1;c<n;c<<=1);c<<=1;
    Prepare(c);
    For(i,0,n) A0[i]=A[i];
    NTT(A0,c,0),NTT(B,c,0);
    For(i,0,c) B[i]=(2*B[i]%P-1LL*A0[i]*B[i]%P*B[i]%P+P)%P;
    NTT(B,c,1);
    For(i,n,c) B[i]=0;
    For(i,0,c) A0[i]=0;
}
void Getsqrt(int *F,int *G,int n)   //F0,Grev
{
    if (n==1) {G[0]=1;return;}
    Getsqrt(F,G,(n+1)/2);
    For(i,0,n) F0[i]=F[i];
    Getrev(G,Grev,n);
    for (c=1;c<n;c<<=1);c<<=1;
    Prepare(c);
    NTT(F0,c,0),NTT(G,c,0),NTT(Grev,c,0);
    For(i,0,c) G[i]=(1LL*G[i]*G[i]%P+F0[i])%P*I2%P*Grev[i]%P;
    NTT(G,c,1);
    For(i,n,c) G[i]=0;
    For(i,0,c) Grev[i]=0;
}

int main()
{
    n=IN(),m=IN();
    C[0]=1;For(i,1,n+1) if ((x=IN())<=m) C[x]=P-4;
    Getsqrt(C,A,m+1);A[0]++;
    Getrev(A,F,m+1);
    For(i,1,m+1) printf("%d\n",2*F[i]%P);
}