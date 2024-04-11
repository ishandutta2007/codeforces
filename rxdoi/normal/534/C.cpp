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
int A[N],n;
long long sum,S;

int main()
{
    n=IN(),scanf("%I64d",&S);
    For(i,0,n) A[i]=IN(),sum+=A[i];
    For(i,0,n)
    {
        int tmp=0;
        tmp+=max(S-(sum-A[i])-1,0LL);
        tmp+=max(A[i]-(S-(n-1)),0LL);
        printf("%d ",tmp);
    }
}