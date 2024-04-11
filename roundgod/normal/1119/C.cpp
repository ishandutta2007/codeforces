#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 505
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
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                a[i][j]^=1;
                a[i+1][j]^=1;
                a[i][j+1]^=1;
                a[i+1][j+1]^=1;
            }
        }
    bool f=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]!=b[i][j]) f=false;
    if(f) puts("Yes"); else puts("No");
    return 0;
}