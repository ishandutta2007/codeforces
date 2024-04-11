/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-21 02:40:35
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,cnt[MAXN],p[8],a,b,c;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            cnt[j]++;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int r=gcd(a,gcd(b,c));
        p[1]=cnt[a]-cnt[gcd(a,b)]-cnt[gcd(a,c)]+cnt[r];
        p[2]=cnt[b]-cnt[gcd(a,b)]-cnt[gcd(b,c)]+cnt[r];
        p[4]=cnt[c]-cnt[gcd(b,c)]-cnt[gcd(a,c)]+cnt[r];
        p[3]=cnt[gcd(a,b)]-cnt[r];
        p[5]=cnt[gcd(a,c)]-cnt[r];
        p[6]=cnt[gcd(b,c)]-cnt[r];
        p[7]=cnt[r];
        int ans=0;
        for(int i=1;i<=7;i++)
            for(int j=i;j<=7;j++)
                for(int k=j;k<=7;k++)
                {
                    bool f=false;
                    if((i&1)&&(j&2)&&(k&4)) f=true;
                    if((i&1)&&(j&4)&&(k&2)) f=true;
                    if((i&2)&&(j&1)&&(k&4)) f=true;
                    if((i&2)&&(j&4)&&(k&1)) f=true;
                    if((i&4)&&(j&1)&&(k&2)) f=true;
                    if((i&4)&&(j&2)&&(k&1)) f=true;
                    if(!f) continue;
                    if(i==j&&j==k) ans+=p[i]*(p[i]+1)*(p[i]+2)/6;
                    else if (i==j) ans+=p[k]*p[i]*(p[i]+1)/2;
                    else if (j==k) ans+=p[i]*p[j]*(p[j]+1)/2;
                    else ans+=p[i]*p[j]*p[k];
                }
        printf("%d\n",ans);
    }
    return 0;
}