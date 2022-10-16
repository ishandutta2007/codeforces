#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n,x,y;
ll preone[MAXN],prezero[MAXN];
int precnt0[MAXN],precnt1[MAXN];
ll sufone[MAXN],sufzero[MAXN];
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    scanf("%d%d",&x,&y);
    for(int i=1;i<=n;i++)
    {
        precnt0[i]=precnt0[i-1];
        precnt1[i]=precnt1[i-1];
        if(str[i]=='1') precnt1[i]++;
        if(str[i]=='0') precnt0[i]++;
    }
    int cnt0=0,cnt1=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='1'||str[i]=='?') {res+=1LL*cnt0*x; cnt1++;}
        else {res+=1LL*cnt1*y; cnt0++;}
        preone[i]=res;
    }
    res=0;
    cnt0=cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='0'||str[i]=='?') {res+=1LL*cnt1*y; cnt0++;}
        else {res+=1LL*cnt0*x; cnt1++;}
        prezero[i]=res;
    }
    res=0;
    cnt0=cnt1=0;
    for(int i=n;i>=1;i--)
    {
        if(str[i]=='1'||str[i]=='?') {res+=1LL*cnt0*y; cnt1++;}
        else {res+=1LL*cnt1*x; cnt0++;}
        sufone[i]=res;
    }
    res=0;
    cnt0=cnt1=0;
    for(int i=n;i>=1;i--)
    {
        if(str[i]=='0'||str[i]=='?') {res+=1LL*cnt1*x; cnt0++;}
        else {res+=1LL*cnt0*y; cnt1++;}
        sufzero[i]=res;
    }
    ll ans=INF;
    //01
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,prezero[i]+sufone[i+1]+1LL*(i-precnt1[i])*(n-i-(precnt0[n]-precnt0[i]))*x+1LL*precnt1[i]*(precnt0[n]-precnt0[i])*y);
    }
    //10
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,preone[i]+sufzero[i+1]+1LL*(i-precnt0[i])*(n-i-(precnt1[n]-precnt1[i]))*y+1LL*precnt0[i]*(precnt1[n]-precnt1[i])*x);
    }
    printf("%lld\n",ans);
    return 0;
}