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
int n,t;
P a[MAXN];
P st[MAXN];
const long double eps=1e-10;
int sgn(long double ta,long double tb)
{
    if(fabs(ta-tb)<eps)return 0;
    if(ta<tb)   return -1;
    return 1;
}
long double find(P x,P y)
{
    return (long double)(y.S-x.S)/(long double)(y.F-x.F)-x.F-y.F;
}
bool check(P x,P y,P z)
{
    long double b=(long double)(y.S-x.S)/(long double)(y.F-x.F)-x.F-y.F;
    long double c=(long double)x.S-b*x.F-(long double)x.F*x.F;
    long double res=(long double)z.F*z.F+(long double)b*z.F+c;
    return (sgn(res,z.S)<=0);
}
void add(P p)
{
    while(t>0&&st[t-1].F==p.F) t--;
    while(t>1&&check(st[t-1],st[t-2],p)) t--;
    st[t++]=p;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) add(a[i]);
    printf("%d\n",t-1);
    return 0;
}