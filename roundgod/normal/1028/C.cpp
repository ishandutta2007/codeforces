/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 00:42:59
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
struct node
{
    int x1,y1,x2,y2;
}a[MAXN],pre[MAXN],suf[MAXN];
node get(node p,node q)
{
    node r=p;
    r.x1=max(r.x1,q.x1);
    r.x2=min(r.x2,q.x2);
    r.y1=max(r.y1,q.y1);
    r.y2=min(r.y2,q.y2);
    return r;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    a[0]=a[n+1]=pre[0]=suf[n+1]=(node){-INF,-INF,INF,INF};
    for(int i=1;i<=n;i++) pre[i]=get(pre[i-1],a[i]);
    for(int i=n;i>=1;i--) suf[i]=get(suf[i+1],a[i]);
    for(int i=1;i<=n;i++)
    {
        node now=get(pre[i-1],suf[i+1]);
        if(now.x1<=now.x2&&now.y1<=now.y2)
        {
            printf("%d %d\n",now.x1,now.y1);
            return 0;
        }
    }
    return 0;
}