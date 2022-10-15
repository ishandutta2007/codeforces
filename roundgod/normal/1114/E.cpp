#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int n,k,m,rem=60;
int ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    scanf("%d",&k);
    return k;
}
int ask2(int x)
{
    printf("> %d\n",x);
    fflush(stdout);
    scanf("%d",&k);
    rem--;
    return k;
}
int find_maxi()
{
    int l=-1,r=1e9;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(ask2(mid)) l=mid; else r=mid;
    }
    return r;
}
int main()
{
    scanf("%d",&n);
    m=find_maxi();
    int d=0;
    for(int i=1;i<=rem;i++)
    {
        int id=wcy()%n+1;
        int x=ask(id);
        if(x!=m) d=__gcd(d,m-x);
    }
    printf("! %d %d\n",m-(n-1)*d,d);
    return 0;
}