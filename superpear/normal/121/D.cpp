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
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

int n,o,ct,lt,ans;
LL cs,k,lc,rc,mini;
LL a[maxn*7];
int b[20];
pair<LL,LL> seg[maxn];
ULL sum1[maxn],db1=0,dc3=0;
double sum2[maxn],db2=0;
priority_queue<LL> sp;

bool ok(LL l,LL r)
{
    if (sum2[lt]-double(l)*(n-lt+1)>k*6) return false;
    ULL e=sum1[lt]-l*(n-lt+1);
    //cout<<l<<" "<<r<<" "<<e<<endl;
    //cout<<lt<<" f "<<e<<endl;
    if (e>k) return false;
    while ((!sp.empty())&&(-sp.top()<=r))
    {
        db1+=-sp.top();
        db2+=-sp.top();
        ++dc3;
        sp.pop();
    }
    //cout<<lt<<" "<<r<<" "<<dc3<<" "<<db2<<" "<<db1<<endl;
    if (double(r)*dc3-db2>k*6) return false;
    e+=r*dc3-db1;
    //cout<<l<<" "<<r<<" "<<e<<endl;
    if (e<=k) return true; else return false;
}

int main()
{
    //freopen("D.in","r",stdin);

    o=0;
    for (int i=1;i<=18;i++)
    {
        memset(b,0,sizeof(b));
        while (b[0]==0)
        {
            cs=0;
            for (int j=1;j<=i;j++)
                if (b[j]==0) cs=cs*10+4; else cs=cs*10+7;
            ++o,a[o]=cs;
            ct=i;
            while (b[ct]==1)
            {
                b[ct]=0,--ct;
            }
            b[ct]=1;
        }
    }
    sort(a+1,a+o+1);

    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>lc>>rc;
        seg[i]=m_p(lc,rc);
    }
    mini=seg[1].w2-seg[1].w1+1;
    for (int i=2;i<=n;i++) mini=min(mini,seg[i].w2-seg[i].w1+1);
    sort(seg+1,seg+n+1);
    sum1[n+1]=0;
    for (int i=n;i>=1;i--) sum1[i]=sum1[i+1]+seg[i].w1;
    sum2[n+1]=0;
    for (int i=n;i>=1;i--) sum2[i]=sum2[i+1]+seg[i].w1;

    int right;

    ans=0;
    right=0;
    lt=1;
    for (int i=1;i<=o;i++)
    {
        while ((lt<=n)&&(seg[lt].w1<a[i])) sp.push(-seg[lt].w2),++lt;
        //cout<<i<<"        "<<lt<<endl;
        while (right+1<i) ++right;
        while ((right+1<=o)&&(ok(a[i],a[right+1]))&&(a[right+1]-a[i]+1<=mini)) ++right;
        ans=max(ans,right-i+1);
        //cout<<i<<" "<<right<<" "<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}