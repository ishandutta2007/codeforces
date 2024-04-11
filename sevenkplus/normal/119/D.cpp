#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 1000010
string a,b;int pa[N],pb[N],pc[N],p[N],le[N],rr[N],n,si=-1,sj=-1;
int main()
{
    getline(cin,a),getline(cin,b);
    if((int)a.length()!=(int)b.length()){puts("-1 -1");return 0;}
    n=(int)a.length();a=" "+a,b=" "+b;
    if(n==1){puts("-1 -1");return 0;}
    p[0]=1;for(int i=1;i<=n;i++)p[i]=p[i-1]*P;
    pa[n+1]=0;for(int i=n;i>=1;i--)pa[i]=pa[i+1]*P+a[i];
    pb[0]=0;for(int i=1;i<=n;i++)pb[i]=pb[i-1]*P+b[i];
    pc[0]=0;for(int i=1;i<=n;i++)pc[i]=pc[i-1]*P+a[i];
    for(int i=1;i<=n;i++)
    {
        int le=1,ri=n-i+1;
        while(le<=ri)
        {
            int mi=(le+ri)/2;
            if(pb[i+mi-1]-pb[i-1]*p[mi]==pa[n-mi+1])le=mi+1;else ri=mi-1;
        }
        rr[i]=i+ri-1;
    }
    for(int i=1,j=1;i<n;i++)
    {
        while(rr[j]<i)j++;
        le[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[n+1-i])break;
        int j=le[n+1-i-1]-1;
        if(j==n+1-i-1)continue;
        if(pb[j]==pc[i+j]-pc[i]*p[j])
        {
            if(si==-1||i>si||i==si&&i+j+1<sj)si=i,sj=i+j+1;
        }
    }
    if(si==-1){puts("-1 -1");return 0;}
    printf("%d %d\n",si-1,sj-1);
    return 0;
}