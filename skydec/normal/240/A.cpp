#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#define ll long long
using namespace std;
struct node
{
    int MAX,MIN;
}c[105];
int m,n,num,k,x,a[105];
bool f[105];
char s[25];
int main()
{  
    freopen("input.txt","r",stdin);    freopen("output.txt","w",stdout);
    int i,j,n1,n2,nn,h;
    while (~scanf("%d%d",&m,&k))
    {
          memset(f,false,sizeof(f));
          for (i=1;i<=k;i++) 
          {
                 scanf("%d",&j);
                 f[j]=true;
          }
          scanf("%d",&n);
          for (i=1;i<=n;i++)
          {
                 scanf("%s%d",s,&num);
                 n1=k,n2=m-k,h=nn=0;
                 for (j=1;j<=num;j++) 
                 {
                        scanf("%d",&x); 
                        if (!x) nn++;
                           else 
                             if (f[x]) h++,n1--;
                                else n2--;
                 }
                 if (n1>=nn) c[i].MAX=h+nn;
                        else c[i].MAX=h+n1;
                 if (n2>=nn) c[i].MIN=h;
                        else c[i].MIN=h+nn-n2;
          } 
          for (i=1;i<=n;i++)
          { 
                 for (j=1;j<=n;j++)
                 if (j!=i && c[j].MAX>c[i].MIN) break;
                 if (j>n) printf("0\n");
                     else
                     {
                           for (j=1;j<=n;j++)
                           if (j!=i && c[j].MIN>c[i].MAX) break; 
                           if (j<=n) printf("1\n");
                                else printf("2\n");
                     }
          }
    }
    return 0;
}