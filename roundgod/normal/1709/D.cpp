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
int n,m,a[MAXN],q;
int st[MAXN][20];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    init(m,a);
    scanf("%d",&q);
    while(q--)
    {
        int xs,ys,xf,yf,k;
        scanf("%d%d%d%d%d",&xs,&ys,&xf,&yf,&k);
        if(ys>yf) {swap(xs,xf); swap(ys,yf);}
        if((yf-ys)%k) {puts("NO"); continue;}
        int downmost=xs+(n-xs)/k*k;
        if(query(ys,yf)>=downmost) {puts("NO"); continue;}
        if(xf>downmost||(downmost-xf)%k) puts("NO"); else puts("YES");
    }
    return 0;
}