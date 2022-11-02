#include<set>
#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int l,r,opt,id;
}A[200020];

int n,L,R,m,A0,ans[100010],sum[100010];
set<pair<int,int> >a;

inline int cmp(const lhy &a,const lhy &b)
{
    if(a.l!=b.l)return a.l<b.l;
    return a.opt>b.opt;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&L,&R);
        A[++A0]=(lhy){L,R,0,i};
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&L,&R,&sum[i]);
        A[++A0]=(lhy){L,R,1,i};
    }
    sort(A+1,A+1+A0,cmp);
    for(int i=1;i<=A0;i++)
        if(A[i].opt)a.insert(make_pair(A[i].r,A[i].id));
        else
        {
            set<pair<int,int> >::iterator it=a.lower_bound(make_pair(A[i].r,0));
            if(it==a.end())return puts("NO"),0;
            ans[A[i].id]=(*it).second;
            sum[(*it).second]--;
            if(!sum[(*it).second])a.erase(it);
        }
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}