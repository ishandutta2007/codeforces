#include<iostream>
#include<stdio.h>
using namespace std;

int a[1007][1007];
int r[1024];
int c[1024];

int main()
    {
    int i,j;
    int n,m,k;
    char o;
    int x,y;
    int sw;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            scanf("%d ",&a[i][j]);
            }
        }
    for(i=0;i<n;i++)
        {
        r[i]=i;
        }
    for(i=0;i<m;i++)
        {
        c[i]=i;
        }
    for(i=0;i<k;i++)
        {
        cin>>o;
        scanf("%d%d",&x,&y);
        //cout<<o<<"\n";
        if(o=='c')
            {
            sw=c[x-1];
            c[x-1]=c[y-1];
            c[y-1]=sw;
            }
        else if(o=='r')
            {
            sw=r[x-1];
            r[x-1]=r[y-1];
            r[y-1]=sw;
            }
        else printf("%d\n",a[r[x-1]][c[y-1]]);
        //printf("krai\n");
        }
    return 0;
    }