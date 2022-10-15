#include<bits/stdc++.h>
#define MAXN 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dskaodo
#define y1 dsakod
#define x2 daskodsa
#define y2 daokdsaoa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,pos[MAXN];
P p[MAXN];
P slope[MAXN*MAXN];
P a[MAXN][MAXN];
ll sum=0;
bool cmp(P x,P y)
{
    P u=a[x.F][x.S],v=a[y.F][y.S];
    if(1LL*u.F*v.S==1LL*v.F*u.S)
    {
        if(x.F!=y.F) return x.F<y.F;
        return x.S<y.S;
    }
    return 1LL*u.F*v.S<1LL*v.F*u.S;    
}
ll xmult(P x,P y,P z)
{
    return 1LL*(y.F-x.F)*(z.S-x.S)-1LL*(y.S-x.S)*(z.F-x.F);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&p[i].F,&p[i].S);
        pos[i]=i;
    }
    sort(p+1,p+n+1);
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            slope[++tot]=P(i,j);
            a[i][j]=P(p[j].F-p[i].F,p[j].S-p[i].S);
        }
    sort(slope+1,slope+tot+1,cmp);
    for(int i=1;i<=tot;i++)
    {
        int u=slope[i].F,v=slope[i].S;
        int l=0,r=n+1,mid,st,ed;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(xmult(p[pos[u]],p[pos[v]],p[mid])>0) l=mid; else r=mid;
        }
        st=l;
        l=0, r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(xmult(p[pos[u]],p[pos[v]],p[mid])<0) r=mid; else l=mid;
        }
        ed=n-r+1;
        swap(p[pos[u]],p[pos[v]]);
        swap(pos[u],pos[v]);
        sum+=1LL*st*ed;
    }
    sum-=1LL*n*(n-1)*(n-2)*(n-3)/12;
    printf("%lld\n",1LL*sum*(n-4)/2);
    return 0;
}