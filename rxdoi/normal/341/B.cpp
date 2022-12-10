#include<cstdio>
using namespace std;

const int Maxn=100000+19,oo=(1<<30)-1;
int A[Maxn],tmp,n,tot=0;

int main()
{
    scanf("%d",&n);
    A[0]=oo;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        int L=0,R=tot+1,Mid;
        while (L<R)
        {
            Mid=(L+R)>>1;
            if (A[Mid]<tmp) L=Mid+1;else R=Mid;
        }
        A[L]=tmp;
        if (L==tot) {tot++;A[tot]=oo;}
    }
    printf("%d\n",tot);
    return 0;
}