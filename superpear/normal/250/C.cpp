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

vector<int> g[maxn];
vector<PII> f[maxn];
int n,k,am,last,ans,na,ansk;
PII cs;
int a[maxn];

int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),g[a[i]].p_b(i);
    am=0;
    for (int i=2;i<=n;i++) if (a[i]!=a[i-1]) ++am;
    for (int i=1;i<=k;i++)
    {
        last=g[i][0];
        for (int j=1;j<g[i].size();j++)
            if (g[i][j]!=g[i][j-1]+1)
            {
                f[i].p_b(m_p(last,g[i][j-1]));
                last=g[i][j];
            }
        f[i].p_b(m_p(last,g[i][g[i].size()-1]));
    }
    ans=maxlongint;ansk=0;
    for (int i=1;i<=k;i++)
    {
        na=am;
        for (int j=0;j<f[i].size();j++)
        {
            cs=f[i][j];
            if (cs.first!=1) --na;
            if (cs.second!=n) --na;
            if ((cs.first!=1)&&(cs.second!=n)&&(a[cs.first-1]!=a[cs.second+1])) ++na;
        }
        if (na<ans)
        {
            ans=na;
            ansk=i;
        }
    }
    cout<<ansk<<endl;

    return 0;
}