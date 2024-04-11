#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=100005;

int n,m,ans1,ans2;
double a1,b1,ek,ans,o1,o2;
int a[maxn],b[maxn],l[maxn],k[maxn];
PII f[maxn];
int *e1,*e2;

double dis(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
    cin>>n>>m>>a1>>b1;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=m_p(a[i],i);
    sort(f+1,f+n+1);
    for (int i=1;i<=n;i++) a[i]=f[i].first,k[i]=f[i].second;
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=m;i++) scanf("%d",&l[i]);
    ans=1e10;ans1=0;ans2=0;
    for (int i=1;i<=m;i++)
    {
        ek=double(b[i])/b1*a1;
        e1=l_b(a+1,a+n+1,ek);
        if (e1==a+n+1) --e1;
        if (e1!=a+1) e2=e1-1; else e2=e1;
        o1=dis(b1,b[i],a1,*e1)+dis(0,0,a1,*e1)+l[i];
        o2=dis(b1,b[i],a1,*e2)+dis(0,0,a1,*e2)+l[i];
        if (o1<ans)
        {
            ans=o1;
            ans1=k[e1-a];
            ans2=i;
        }
        if (o2<ans)
        {
            ans=o2;
            ans1=k[e2-a];
            ans2=i;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}