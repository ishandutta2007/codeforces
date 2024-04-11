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

vector<PII> f;
int n,m,c1,c2;

int main()
{
    cin>>n>>m;
    LL ans=0;
    for (int b=1;b<=n;b++)
    {
        c1=b-1;
        if ((LL)b*b>=m) c2=floor(sqrt((LL)b*b-m)-(1e-9))+1; else c2=0;
        ans-=(LL)(c1-c2+1)*2;
        if (c1>=c2)
        {
            if (c2==0)
            {
                f.p_b(m_p(-b,-b));
                ++c2;
            }
            if (c1>=c2)
            {
                f.p_b(m_p(-b+c2,-b+c1));
                f.p_b(m_p(-b-c2,-b-c1));
            }
        }
        ans+=min((LL)b*b,(LL)m)*2;
    }
    //cout<<ans<<endl;
    for (int i=0;i<f.size();i++)
        if (f[i].first>f[i].second) swap(f[i].first,f[i].second);
    sort(f.begin(),f.end());
    //for (int i=0;i<f.size();i++) cout<<f[i].first<<" "<<f[i].second<<endl;
    for (int i=1;i<f.size();i++)
    {
        if (f[i].first<=f[i-1].second) f[i].first=f[i-1].second+1;
        if (f[i].second<f[i].first) f[i].second=f[i].first-1;
    }
    for (int i=0;i<f.size();i++) ans+=(LL)f[i].second-f[i].first+1;

    cout<<ans<<endl;

    return 0;
}