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
typedef pair<pair<LL,LL>,int> PIII;

const int maxn=100005;

struct three
{
    int t,s,p,uv;
} a[maxn];

bool cmp(three a,three b)
{
    return a.t<b.t;
}

priority_queue<PIII> f;
PIII q[maxn*2],cs;
LL tt[maxn];
int n,o;
LL finalt;

LL times(int pio)
{
    LL e;
    for (int i=1;i<=n;i++) if (a[i].p==-1) a[i].p=pio;
    memset(tt,0,sizeof(tt));
    o=0;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<n;i++)
    {
        //cout<<pio<<"  "<<a[i].uv<<" "<<a[i].p<<endl;
        f.push(m_p(m_p(a[i].p,a[i].s),a[i].uv));
        e=a[i].t;
        while ((!f.empty()&&(f.top().w1.w2<=a[i+1].t-e)))
        {
            ++o;
            q[o]=m_p(m_p(e,e+f.top().w1.w2),f.top().w2);
            tt[f.top().w2]=e+f.top().w1.w2;
            e+=(LL)f.top().w1.w2;
            f.pop();
        }
        if (!f.empty())
        {
            cs=f.top();f.pop();
            ++o;
            q[o]=m_p(m_p(e,a[i+1].t-1),cs.w2);
            cs.w1.w2-=(a[i+1].t-e);
            f.push(cs);
        }
    }
    f.push(m_p(m_p(a[n].p,a[n].s),a[n].uv));
    e=a[n].t;
    while (!f.empty())
    {
        ++o;
        q[o]=m_p(m_p(e,e+f.top().w1.w2),f.top().w2);
        tt[f.top().w2]=e+f.top().w1.w2;
        e+=(LL)f.top().w1.w2;
        f.pop();
    }
    for (int i=1;i<=n;i++) if (a[i].p==pio) {a[i].p=-1;return tt[a[i].uv];}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].s>>a[i].p;
        a[i].uv=i;
    }
    cin>>finalt;

    vector<int> oc;
    int jc[maxn];
    int left,right,mid;
    LL cc;

    for (int i=1;i<=n;i++) jc[i]=a[i].p;
    sort(jc+1,jc+n+1);
    if (jc[2]!=1) oc.p_b(jc[2]-1);
    for (int i=2;i<=n;i++)
        if ((i==n)||(jc[i]+1!=jc[i+1])) oc.p_b(jc[i]+1);
    left=0;
    right=oc.size()-1;
    while (left<=right)
    {
        mid=(left+right)/2;
        cc=times(oc[mid]);
        //cout<<oc[mid]<<" "<<cc<<endl;
        if (cc==finalt)
        {
            cout<<oc[mid]<<endl;
            for (int i=1;i<=n;i++) cout<<tt[i]<<" ";cout<<endl;
            return 0;
        }
        if (cc>finalt) left=mid+1; else right=mid-1;
    }

    return 0;
}