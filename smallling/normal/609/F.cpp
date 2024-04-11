#include<set>
#include<cstdio>
#include<algorithm>

#define N 200020
#define fi first
#define se second
#define mp make_pair

using namespace std;

multiset<pair<int,int> >A;
multiset<pair<int,int> >::iterator it;
int n,m,p,b,now,x[N],t[N],a[N],ans[N],what[N];
long long tree[N<<2],Ans[N];

void ask(int k,int l,int r)
{
    if(l==r)
    {
        if(tree[k]<p||a[l]>p)now=0;
        else now=what[l];
        return;
    }
    int mid=(l+r)>>1;
    if(tree[k<<1]>=p)ask(k<<1,l,mid);
    else ask(k<<1|1,mid+1,r);
}

void add(int k,int l,int r,int ll,int val)
{
    if(l==r)
    {
        tree[k]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=ll)add(k<<1,l,mid,ll,val);
    else add(k<<1|1,mid+1,r,ll,val);
    tree[k]=max(tree[k<<1],tree[k<<1|1]);
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&t[i]),a[i]=x[i];
    sort(a+1,a+1+n);
    a[0]=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;i++)
        x[i]=lower_bound(a+1,a+1+a[0],x[i])-a,add(1,1,n,x[i],a[x[i]]+t[i]),what[x[i]]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&p,&b);
        ask(1,1,n);
        if(now)
        {
            ans[now]++;
            Ans[now]+=b;
            add(1,1,n,x[now],b);
            while(A.size())
            {
                it=A.lower_bound(mp(a[x[now]],0));
                if(it==A.end())break;
                p=(*it).fi;
                ask(1,1,n);
                if(!now)break;
                ans[now]++;
                Ans[now]+=(*it).se;
                add(1,1,n,x[now],(*it).se);
                A.erase(it);
            }
        }
        else A.insert(mp(p,b));
    }
    for(int i=1;i<=n;i++)
        printf("%d %I64d\n",ans[i],t[i]+Ans[i]);
}