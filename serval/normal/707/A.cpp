#include <cstdio>
using namespace std;
int n,m,i,j;
char op;
bool isbw;
int main()
{
    isbw=1;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            op=0;
            while (op!='C'&&op!='M'&&op!='Y'&&op!='B'&&op!='W'&op!='G')
                scanf("%c",&op);
            if (op=='C'||op=='M'||op=='Y')
                isbw=0;
        }
    if (isbw)
        printf("#Black&White");
    else
        printf("#Color");
    return 0;
}