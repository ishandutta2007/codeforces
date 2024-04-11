#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
int p[MAXN],a[MAXN],bas[MAXN][20],cnt[MAXN];
void construct(int id)
{
    cnt[id]=cnt[id-1];
    for(int i=0;i<20;i++) bas[id][i]=bas[id-1][i];
    int x=a[id];
    for(int j=19;j>=0;j--)
    {
        if(x&(1<<j))
        {
            if(!bas[id][j])
            {
                bas[id][j]=x;
                cnt[id]++;
                break;
            }
            x^=bas[id][j];
        }
    }
}
int query(int id,int x)
{
    for(int j=19;j>=0;j--)
    {
        if(x&(1<<j))
        {
            if(!bas[id][j]) return 0;
            x^=bas[id][j];
        }
    }
    return p[id-cnt[id]];
}
int main()
{
    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=2LL*p[i-1]%MOD;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        construct(i);
    }
    for(int i=0;i<q;i++)
    {
        int l,x;
        scanf("%d%d",&l,&x);
        printf("%d\n",query(l,x));
    }
    return 0;
}