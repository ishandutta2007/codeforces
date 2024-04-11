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
int a[MAXN][MAXN],b[MAXN][MAXN];
vector<int> v1,v2;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    bool f=true;
    for(int i=1;i<=m;i++)
    {
        v1.clear();v2.clear();
        int x=1,y=i;
        do
        {
            v1.push_back(a[x][y]);v2.push_back(b[x][y]);
            x++;y--;
        }while(x>=1&&x<=n&&y>=1&&y<=m);
        sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
        for(int j=0;j<(int)v1.size();j++) if(v1[j]!=v2[j]) f=false;
    }
    for(int i=2;i<=n;i++)
    {
        v1.clear();v2.clear();
        int x=i,y=m;
        do
        {
            v1.push_back(a[x][y]);v2.push_back(b[x][y]);
            x++;y--;
        }while(x>=1&&x<=n&&y>=1&&y<=m);
        sort(v1.begin(),v1.end());sort(v2.begin(),v2.end());
        for(int j=0;j<(int)v1.size();j++) if(v1[j]!=v2[j]) f=false;
    }
    if(f) puts("YES"); else puts("NO");
    return 0;
}