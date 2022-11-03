/*
ID: Sfiction
OJ: CF
PROB: 266B
*/
#include <cstdio>
int main()
{
    int n,t;
    int i,j;
    char a[51],b[51];
    scanf("%d%d",&n,&t);
    scanf("%s",a);
    for (i=0;i<t;++i)
    {
        for (j=0;j<n;++j) b[j]=a[j];
        b[j]=0;
        for (j=1;j<n;++j)
            if (a[j]=='G'&&a[j-1]=='B')
            {
                b[j]='B';
                b[j-1]='G';
            }
        for (j=0;j<n;++j) a[j]=b[j];
    }
    printf("%s",b);
    return 0;
}