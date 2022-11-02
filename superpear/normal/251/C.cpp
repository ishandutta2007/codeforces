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

int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

LL a,b,ans,oj;
int k,e,c,ec,ansk;

int main()
{
    cin>>a>>b>>k;
    e=1;
    for (int i=1;i<=k;i++) e=e*i/gcd(e,i);
    ansk=0;
    c=e;
    while (c>0)
    {
        ec=c-1;
        for (int i=1;i<=k;i++) ec=min(ec,c-c%i);
        ++ansk;
        c=ec;
    }
    ans=0;
    while ((a>b)&&(a%e!=0))
    {
        oj=a-1;
        for (int i=1;i<=k;i++) if (a-a%i>=b) oj=min(oj,a-a%i);
        ++ans;
        a=oj;
    }
    if (a==b) cout<<ans<<endl; else
    {
        ans+=(LL)(a/e-b/e-1)*ansk;
        a=e;b%=e;
        while (a>b)
        {
            oj=a-1;
            for (int i=1;i<=k;i++) if (a-a%i>=b) oj=min(oj,a-a%i);
            ++ans;
            a=oj;
        }
        cout<<ans<<endl;
    }

    return 0;
}