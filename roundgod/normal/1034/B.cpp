/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 01:36:44
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
ll n,m;
int main()
{
    scanf("%lld%lld",&n,&m);
    if(n>m) swap(n,m);
    if(n<=2&&m<=2) puts("0");
    else if(n==1)
    {
        if(m%6<=3) printf("%lld\n",(m/6)*6);
        else printf("%lld\n",(m/6*6)+((m%6)-3)*2);
    }
    else if(n==2)
    {
        if(m==3) puts("4");
        else if(m==7) puts("12");
        else printf("%lld\n",n*m);
    }
    else if((n&1)&&(m&1))
    {
        printf("%lld\n",n*m-1);
    }
    else printf("%lld\n",n*m);
    return 0;
}