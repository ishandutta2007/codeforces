/*
ID: SFiction
OJ: CF
PROB: 294B
*/
#include <cstdio>
#include <cstdlib>
const int MAXN=100;
int a[MAXN],lena;
int b[MAXN],lenb;
int Comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int N,i,j,t;
    int width,thick,ans;
    scanf("%d",&N);
    for (i=0;i<N;++i)
    {
        scanf("%d",&t);
        if (t==1) scanf("%d",&a[++lena]);
        else scanf("%d",&b[++lenb]);
    }
    qsort(a+1,lena,sizeof(int),Comp);
    qsort(b+1,lenb,sizeof(int),Comp);
    ans=1<<30;
    for (i=0;i<=lena;++i)
    {
        width=a[i];
        thick=lena-i+lenb*2;
        for (j=0;j<=lenb;++j,thick-=2)
        {
            width+=b[j];
            if (width<=thick)
            {
                if (thick<ans) ans=thick;
            }
            else break;
        }
        a[i+1]+=a[i];
    }
    printf("%d",ans);
    return 0;
}