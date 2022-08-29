#include<stdio.h>
using namespace std;
long map[55][55];
int x[2505];
int y[2505];
int n;
int c[55];
int pp1[2505];
int pp2[2505];
int pp3[2505],pp4[2505];
int main()
{
    scanf("%ld",&n);long ppt=0;
    for(int i=1;i<=n;i++)
    {
            scanf("%ld",&c[i]);
            for(int j=1;j<=c[i];j++)
            {
                    ppt++;
                    x[ppt]=i;
                    y[ppt]=j;
                    }
                    }
    //printf("%ld\n",ppt);
    int tot=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=c[i];j++)
    scanf("%ld",&map[i][j]);
    for(int i=1;i<=ppt;i++)
    {
            bool flag=false;
            if(map[x[i]][y[i]]==i)flag=true;
            for(int j=1;j<=n;j++)
            for(int k=1;k<=c[j];k++)
            if(!flag)
            if(map[j][k]==i)
            {
                            int tmp=map[j][k];
                            map[j][k]=map[x[i]][y[i]];
                            map[x[i]][y[i]]=tmp;
                            tot++;
                            pp1[tot]=j;
                            pp2[tot]=k;
                            pp3[tot]=x[i];
                            pp4[tot]=y[i];
                            flag=true;
                            break;
                            }
            }
    printf("%ld\n",tot);
    for(int i=1;i<=tot;i++)printf("%d %d %d %d\n",pp1[i],pp2[i],pp3[i],pp4[i]);
     //for(;;);
     return 0;
}