#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXC 45
#define MAXQ 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,c,q;
char str[MAXN];
ll l[MAXC],r[MAXC];
ll query[MAXQ];
ll len[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&c,&q);
        scanf("%s",str+1);
        len[0]=n;
        for(int i=1;i<=c;i++)
        {
            scanf("%lld%lld",&l[i],&r[i]);
            len[i]=len[i-1]+r[i]-l[i]+1;
        }
        for(int i=0;i<q;i++)
            scanf("%lld",&query[i]);
        for(int i=c;i>=1;i--)
            for(int j=0;j<q;j++)
                if(query[j]>len[i-1]) query[j]=(query[j]-len[i-1]+l[i]-1);
        for(int i=0;i<q;i++) printf("%c\n",str[query[i]]);
    }
    return 0;
}