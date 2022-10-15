#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
typedef vector<int> vec;
typedef vector<vec> mat;
int q,n,m;
string str[MAXN];
int cntr[MAXN],cntc[MAXN];
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<n;i++) cntr[i]=0;
        for(int j=0;j<m;j++) cntc[j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='*') {cntr[i]++; cntc[j]++;}
        int ans=n+m-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=min(ans,n+m-1-(cntr[i]+cntc[j]-(str[i][j]=='*')));
        printf("%d\n",ans);
    }
    return 0;
}