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

const int N=2e5+19;
typedef long long LL;
LL A[N],n,w;

int main()
{
    n=IN(),w=IN();
    For(i,1,2*n+1) A[i]=IN();
    sort(A+1,A+2*n+1);
    printf("%.10lf\n",min(min(1.0*A[1],A[n+1]/2.0),1.0*w/(3.0*n))*3.0*n);
}