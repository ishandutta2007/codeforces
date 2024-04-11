#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m;
char str[MAXN][MAXN];
int down[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=m;i++) down[n][i]=n;
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(str[i][j]==str[i+1][j]) down[i][j]=down[i+1][j]; else down[i][j]=i;
    int x,y,z,len,pos,cnt;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        x=y=z=len=-1; cnt=0;
        for(int j=1;j<=m;j++)
        {
            pos=i;
            int c1=str[pos][j]-'a';
            int len1=down[pos][j]-pos+1;
            pos=down[pos][j]+1;
            if(pos>n)
            { 
                x=y=z=len=-1; cnt=0;
                continue;
            }
            int c2=str[pos][j]-'a';
            int len2=down[pos][j]-pos+1;
            pos=down[pos][j]+1;
            if(pos>n)
            {
                x=y=z=len=-1; cnt=0;
                continue;
            }
            int c3=str[pos][j]-'a';
            int len3=down[pos][j]-pos+1;
            if(len1!=len2||len2>len3)
            {
                x=y=z=len=-1; cnt=0;
                continue;
            }
            if(x==c1&&y==c2&&z==c3&&len==len1)
            {
                ans+=cnt+1;
                cnt++;
            }
            else
            {
                ans++;
                cnt=1;
                x=c1; y=c2; z=c3; len=len1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}