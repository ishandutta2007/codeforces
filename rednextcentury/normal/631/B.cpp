#include<bits/stdc++.h>
using namespace std;
int r[1000000][2];
int c[1000000][2];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
    {
        int typ,id,col;
        scanf("%d%d%d",&typ,&id,&col);
        if  (typ==1)
        {
            r[id][0]=col;
            r[id][1]=i+1;
        }
        else
        {
            c[id][0]=col;
            c[id][1]=i+1;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int x=0;
            if (r[i][1]>c[j][1])
                x=r[i][0];
            else
                x=c[j][0];
            printf("%d ",x);
        }
        printf("\n");
    }
}