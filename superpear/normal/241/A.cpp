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

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

int n,k,d[10000],s[10000],maxc,ful,ans;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=n;i++) cin>>s[i];
    maxc=0;
    ans=0;
    ful=0;
    for (int i=1;i<=n;i++)
    {
        maxc=max(maxc,s[i]);
        ful+=s[i];
        while (ful<d[i])
        {
            ful+=maxc;
            ans+=k;
        }
        ful-=d[i];
        ans+=d[i];
    }
    cout<<ans<<endl;

    return 0;
}