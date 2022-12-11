#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int Mod=1e9+7;
struct Matrix {int n,m,s[1<<7][1<<7];} A,F;
int w[8];

Matrix operator * (Matrix A,Matrix B)
{
    Matrix C;C.n=A.n,C.m=B.m;
    For(i,0,C.n) For(j,0,C.m) C.s[i][j]=0;
    For(i,0,C.n) For(k,0,A.m) For(j,0,C.m) (C.s[i][j]+=1LL*A.s[i][k]*B.s[k][j]%Mod)%=Mod;
    return C;
}
Matrix Pow(Matrix A,int b)
{
    Matrix res;res.n=res.m=A.n;
    For(i,0,A.n) For(j,0,A.m) res.s[i][j]=(i==j);
    for (;b;b>>=1,A=A*A) if (b&1) res=res*A;
    return res;
}

int main()
{
    For(i,1,8) scanf("%d",&w[i]);
    F.n=1,F.s[0][1]=1;
    For(t,1,8)
    {
        A.n=A.m=1<<t;
        For(i,0,A.n) For(j,0,A.m) A.s[i][j]=0;
        For(i,0,1<<t) For(j,0,1<<t) For(k,0,1<<t-1)
        {
            int tmp=k<<1|1|1<<t;
            if (!(tmp&tmp>>1&i&j)) A.s[i][j]++;
        }
        F.m=1<<t,F=F*Pow(A,w[t]);
        if (t<7) For(i,0,1<<t) F.s[0][i|(1<<t)]=F.s[0][i],F.s[0][i]=0;
    }
    printf("%d\n",F.s[0][127]);
}