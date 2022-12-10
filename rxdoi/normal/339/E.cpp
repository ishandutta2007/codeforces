#include<cstdio>
#include<cstdlib>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1000+19;
int A[N],L[4],R[4],n;

void DFS(int x)
{
    int f=1;
    For(i,1,n+1) if (A[i]!=i) f=0;
    if (f)
    {
        printf("%d\n",x);
        for (int i=x-1;~i;i--) printf("%d %d\n",L[i],R[i]);exit(0);
    }
    if (x==3) return;
    For(i,1,n+1) if (A[i]!=i&&(abs(A[i]-A[i-1])>1||abs(A[i]-A[i+1])>1))
    {
        L[x]=i;
        For(j,i+1,n+1) if (A[j]!=j&&(abs(A[j]-A[j-1])>1)||abs(A[j]-A[j+1])>1)
        {
            reverse(A+i,A+j+1);R[x]=j;
            DFS(x+1);
            reverse(A+i,A+j+1);
        }
    }
}

int main()
{
    scanf("%d",&n);A[0]=A[n+1]=-1;
    For(i,1,n+1) scanf("%d",&A[i]);
    DFS(0);
}