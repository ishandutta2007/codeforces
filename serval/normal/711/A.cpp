#include <cstdio>
using namespace std;
char map[1005][15],tmp;
int n,i,j;
bool found;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=5;j++)
        {
            tmp=0;
            while (tmp!='O'&&tmp!='X'&&tmp!='|')
                scanf("%c",&tmp);
            map[i][j]=tmp;
        }
    for (i=1;i<=n;i++)
    {
        if (map[i][1]=='O'&&map[i][2]=='O')
        {
            map[i][1]=map[i][2]='+';
            found=1;
            break;
        }
        if (map[i][4]=='O'&&map[i][5]=='O')
        {
            map[i][4]=map[i][5]='+';
            found=1;
            break;
        }
    }
    if (found)
    {
        printf("YES\n");
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=5;j++)
                printf("%c",map[i][j]);
            printf("\n");
        }
    }
    else
        printf("NO\n");
    return 0;
}