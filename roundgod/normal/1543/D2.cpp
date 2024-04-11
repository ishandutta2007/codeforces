#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
int t,n,k;
int base[20];
int state;
int tmp[20];
int tmp2[20];
int ask(int x)
{
    memset(tmp,0,sizeof(tmp));
    memset(tmp2,0,sizeof(tmp2));
    int now=0;
    while(x)
    {
        tmp[now]=x%k;
        x/=k; now++;
    }
    for(int i=0;i<19;i++) 
    {
        if(state==0)
        {
            tmp2[i]=(tmp[i]+base[i])%k;
        }
        else tmp2[i]=(base[i]-tmp[i]+k)%k;
    }
    int res=0;
    for(int i=18;i>=0;i--)
        res=res*k+tmp2[i];
    printf("%d\n",res);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    state^=1;
    for(int i=0;i<19;i++) base[i]=(tmp2[i]-base[i]+k)%k;
    return y;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(base,0,sizeof(base));
        state=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n-1;i++)
        {
            if(ask(i)) break;
        }
    }
    return 0;
}