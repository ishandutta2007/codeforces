#include<ctime>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100000+19,P=1e9+7,Len=10000000;
int A[N],f[N],Fac[N],Inv[N],V[N],tmp=1,n,k,tot,oth,x;
char Buf[Len],*B=Buf;

int IN()
{
    int c,x;
    while (!isdigit(c=*B++));x=c-'0';
    while (isdigit(c=*B++)) x=(x<<1)+(x<<3)+c-'0';return x;
}

bool Check(int x)
{
    if (!x) return 0;
    for (;x;x/=10) if (x%10!=4&&x%10!=7) return 0;
    return 1;
}
int Pow(int a,int b)
{
    int res=1;
    for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
    return res;
}
int C(int n,int m) {return 1LL*Fac[n]*Inv[m]%P*Inv[n-m]%P;}
inline void Add(int &x,int y) {x=x+y;if (x>=P) x-=P;}

int main()
{
    fread(Buf,1,Len,stdin);
    n=IN(),k=IN();

    Fac[0]=1;For(i,1,n+1) Fac[i]=1LL*i*Fac[i-1]%P;
    Inv[n]=Pow(Fac[n],P-2);
    for (int i=n;i;i--) Inv[i-1]=1LL*Inv[i]*i%P;

    For(i,1,n+1) A[i]=IN();
    sort(A+1,A+n+1);
    For(i,2,n+2)
        if (i==n+1||A[i]!=A[i-1])
        {
            if (Check(A[i-1])) V[++*V]=tmp;else oth+=tmp;
            tmp=1;
        } else tmp++;
    For(i,0,oth+1) f[i]=C(oth,i);
    For(i,1,*V+1)
    {
        int tmp=V[i];
        for (int j=min(i+oth,k);j;j--) Add(f[j],1LL*f[j-1]*tmp%P);//f[j]=(f[j]+1LL*f[j-1]*V[i]%P)%P;
    }
    printf("%d\n",f[k]);
}