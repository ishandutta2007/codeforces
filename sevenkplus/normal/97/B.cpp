#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
set<PII> A;
PII a[10010];int n;
void ff(int l,int r)
{
    if(l==r-1)return;
    int m=(l+r)/2;
    for(int i=l;i<r;i++)A.insert(mp(a[m].fi,a[i].se));
    ff(l,m),ff(m,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].fi,&a[i].se),A.insert(a[i]);
    sort(a,a+n);ff(0,n);
    printf("%d\n",(int)A.size());
    for(set<PII>::iterator i=A.begin();i!=A.end();i++)
        printf("%d %d\n",i->fi,i->se);
    return 0;
}