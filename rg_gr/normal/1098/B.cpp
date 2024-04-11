#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
char** a;
int cow[303000][4][2],row[300006][4][2];//ATGC
int dist(char a,char b,char c,char d,int n,int m)
{
    int ans=0;
    for(int i=0;i<m;i+=2)ans+=max(cow[i][a][0]+cow[i][b][1],cow[i][b][0]+cow[i][a][1]);
    for(int i=1;i<m;i+=2)ans+=max(cow[i][c][0]+cow[i][d][1],cow[i][d][0]+cow[i][c][1]);
    return ans;
}
int dist_(char a,char b,char c,char d,int n,int m)
{
#define cow row
    int ans=0;
    for(int i=0;i<n;i+=2)ans+=max(cow[i][a][0]+cow[i][b][1],cow[i][b][0]+cow[i][a][1]);;
    //puts("");
    for(int i=1;i<n;i+=2)ans+=max(cow[i][c][0]+cow[i][d][1],cow[i][d][0]+cow[i][c][1]);;
    return ans;
#undef cow
}
void filcow(int aa,int b,int co,int n)
{
    for(int i=0;i<n;i++)
        a[i][co]=(i&1)?b:aa;
}
void filrow(int aa,int b,int ro,int m)
{
    //printf("filling %d %d %d %d\n",aa,b,ro,m);
    for(int i=0;i<m;i++)
        a[ro][i]=(i&1)?b:aa;
}
int printcow(int a,int b,int c,int d,int n,int m)
{
    //printf("%d\n",m);
    //printf("%d %d %d %d c \n",a,b,c,d);
    for(int i=0;i<m;i+=2)
    {
        if(cow[i][a][0]+cow[i][b][1]>cow[i][b][0]+cow[i][a][1])filcow(a,b,i,n);
        else filcow(b,a,i,n);
    }
    for(int i=1;i<m;i+=2)
    {
        if(cow[i][c][0]+cow[i][d][1]>cow[i][d][0]+cow[i][c][1])filcow(c,d,i,n);
        else filcow(d,c,i,n);
    }
    return 0;
}
int printrow(int a,int b,int c,int d,int n,int m)
{
    //printf("%d %d %d %d r \n",a,b,c,d);
#define cow row
    for(int i=0;i<n;i+=2)
    {
        if(cow[i][a][0]+cow[i][b][1]>cow[i][b][0]+cow[i][a][1])filrow(a,b,i,m);
        else filrow(b,a,i,m);
    }
    for(int i=1;i<n;i+=2)
    {
        if(cow[i][c][0]+cow[i][d][1]>cow[i][d][0]+cow[i][c][1])filrow(c,d,i,m);
        else filrow(d,c,i,m);
    }
#undef cow
    return 0;
}
char mmm[5]="ATGC";
inline int print(int n,int m)
{
    for(int i=0;i<n;i++,puts(""))for(int j=0;j<m;j++)putchar(mmm[a[i][j]]);
    return 0;
}
signed main()
{
    int n=read(),m=read();
    a=new char*[n];
    for(int i=0;i<n;i++)a[i]=new char[m+1],scanf("%s",a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='A')a[i][j]=0;
            else if(a[i][j]=='T')a[i][j]=1;
            else if(a[i][j]=='G')a[i][j]=2;
            else a[i][j]=3;
            cow[j][a[i][j]][(i)&1]++;
            row[i][a[i][j]][(j)&1]++;
        }
    }
    int ct,ca,cg,at,tg,ag,mina;
    int rct,rca,rcg,rat,rtg,rag,minb;
    ct=dist(3,1,0,2,n,m);
    ca=dist(3,0,1,2,n,m);
    cg=dist(3,2,0,1,n,m);
    at=dist(0,1,3,2,n,m);
    tg=dist(2,1,3,0,n,m);
    ag=dist(0,2,1,3,n,m);
    rct=dist_(3,1,0,2,n,m);
    rca=dist_(3,0,1,2,n,m);
    rcg=dist_(3,2,0,1,n,m);
    rat=dist_(0,1,3,2,n,m);
    rtg=dist_(2,1,3,0,n,m);
    rag=dist_(0,2,1,3,n,m);
    mina=min(ct,min(ca,min(cg,min(at,min(tg,ag)))));
    minb=min(rct,min(rca,min(rcg,min(rat,min(rtg,rag)))));
    int minn=min(mina,minb);

    //printf("%d %d %d %d %d %d\n",rct,rca,rcg,rat,rtg,rag);
    if(minn==ct){printcow(3,1,0,2,n,m);print(n,m);return 0;}
    if(minn==ca){printcow(3,0,1,2,n,m);print(n,m);return 0;}
    if(minn==cg){printcow(3,2,0,1,n,m);print(n,m);return 0;}
    if(minn==at){printcow(0,1,3,2,n,m);print(n,m);return 0;}
    if(minn==tg){printcow(2,1,3,0,n,m);print(n,m);return 0;}
    if(minn==ag){printcow(0,2,1,3,n,m);print(n,m);return 0;}
    if(minn==rct){printrow(3,1,0,2,n,m);print(n,m);return 0;}
    if(minn==rca){printrow(3,0,1,2,n,m);print(n,m);return 0;}
    if(minn==rcg){printrow(3,2,0,1,n,m);print(n,m);return 0;}
    if(minn==rat){printrow(0,1,3,2,n,m);print(n,m);return 0;}
    if(minn==rtg){printrow(2,1,3,0,n,m);print(n,m);return 0;}
    if(minn==rag){printrow(0,2,1,3,n,m);print(n,m);return 0;}
    //ATGC

    delete[ ] a;
}