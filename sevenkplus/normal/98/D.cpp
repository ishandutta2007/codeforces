#include<cstdio>
#include<algorithm>
using namespace std;
int a[22],n,m,X[1048577],Y[2048577],L;
void gg(int x,int A,int B)
{
    if(x+1==n)
    {
        for(int i=0;i<a[x];i++)X[L]=A,Y[L++]=B;
        return;
    }
    int C=6-A-B;
    gg(x+1,A,C);
    for(int i=0;i<a[x];i++)X[L]=A,Y[L++]=B;
    gg(x+1,C,B);
}
void ff(int x,int A,int B)
{
    int C=6-A-B;
    if(x+1==n)
    {
        for(int i=0;i<a[x]-1;i++)X[L]=A,Y[L++]=C;
        X[L]=A,Y[L++]=B;
        for(int i=0;i<a[x]-1;i++)X[L]=C,Y[L++]=B;
        return;
    }
    if(a[x]==1){gg(x,A,B);return;}
    gg(x+1,A,B);
    for(int i=0;i<a[x];i++)X[L]=A,Y[L++]=C;
    gg(x+1,B,A);
    for(int i=0;i<a[x];i++)X[L]=C,Y[L++]=B;
    ff(x+1,A,B);
}
int main()
{
    scanf("%d",&m);
    for(int i=0,la=-1,x;i<m;i++)
    {
        scanf("%d",&x);
        if(x==la)a[n-1]++;
        else la=x,a[n++]=1;
    }
    ff(0,1,3);
    printf("%d\n",L);
    for(int i=0;i<L;i++)printf("%d %d\n",X[i],Y[i]);
    return 0;
}