#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=500010;
const int inf=0x7f7f7f7f;

map<int,int> mp;
map<int,int>::iterator it;

struct lhy{
    int b,i,l;
}a[maxn];

int n,ans;

inline int cmp(const lhy &a,const lhy &b)
{
    if(a.b^b.b)return a.b<b.b;
    if(a.i^b.i)return a.i>b.i;
    return a.l<b.l;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].b);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].i);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].l);
    sort(a+1,a+n+1,cmp);
    mp[inf]=-inf;
    mp[-inf]=inf;
    for(int i=n;i>=1;i--)
    {
        it=mp.upper_bound(a[i].i);
        if(a[i].l<it->second)
            ans++;
        else
        if(mp[a[i].i]<a[i].l)
        {
            mp[a[i].i]=a[i].l;
            for(it=--mp.lower_bound(a[i].i);it->second<=a[i].l;)
                mp.erase(it--);
        }
    }
    printf("%d",ans);
}