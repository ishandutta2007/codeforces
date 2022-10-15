/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 11:03:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 20
#define MAXM 100005
#define INF 1000000000
#define REV 500000004
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXM];
int cnt[1<<20],cnt2[1<<20];
void FWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=(x+y)%MOD,a[i+j+d]=(x-y+MOD)%MOD;     
                //and:a[i+j]=x+y;    
                //or:a[i+j+d]=x+y;    
            }    
}    
    
void UFWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=1LL*(x+y)*REV%MOD,a[i+j+d]=(1LL*(x-y)*REV%MOD+MOD)%MOD;      
                //and:a[i+j]=x-y;    
                //or:a[i+j+d]=y-x;    
            }    
}    
string str;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        cin>>str;
        for(int j=0;j<m;j++) a[i][j]=str[j]-'0';
    }
    for(int i=0;i<(1<<n);i++) 
    {
        int x=__builtin_popcount(i);
        cnt[i]=min(x,n-x);
    }
    for(int i=0;i<m;i++)
    {
        int x=0;
        for(int j=0;j<n;j++) x=x*2+a[j][i];
        cnt2[x]++;
    }
    //for(int i=0;i<(1<<n);i++) printf("%d %d\n",cnt[i],cnt2[i]);
    int ans=INF;
    FWT(cnt,(1<<n));FWT(cnt2,(1<<n));
    for(int i=0;i<(1<<n);i++) cnt2[i]=1LL*cnt2[i]*cnt[i]%MOD;
    UFWT(cnt2,(1<<n));
    //for(int i=0;i<(1<<n);i++) printf("%d\n",cnt2[i]);
    for(int i=0;i<(1<<n);i++) ans=min(ans,cnt2[i]);
    printf("%d\n",ans);
    return 0;
}