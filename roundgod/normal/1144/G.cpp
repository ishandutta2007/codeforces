#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define inc adskopads
#define dec dakodas
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
bool added[MAXN];
int inc,dec;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(added,false,sizeof(added));
    inc=-INF,dec=INF;
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=inc&&a[i]>=dec)
        {
            f=false;
            break;
        }
        else if(a[i]>inc&&a[i]<dec)
        {
            if(i==n) {added[i]=true; break;}
            if(a[i+1]>a[i]) {added[i]=true; inc=a[i];}
            else dec=a[i];
        }
        else if(a[i]>inc) {added[i]=true; inc=a[i];}
        else dec=a[i];
    }
    if(!f) {puts("NO"); return 0;}
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",added[i]?0:1);
    return 0;
}