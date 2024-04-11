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

long long n;
int x1,x2,ans,now,tc;
int main()
{
    cin>>n;
    ans=maxlongint;
    for (int t=1;t<=180;t++)
    {
        x1=(-t+sqrt(t*t+4*n))/2;
        x2=(-t-sqrt(t*t+4*n))/2;
        if ((x1>0)&&((long long)x1*x1+(long long)t*x1==n))
        {
            now=0;tc=x1;
            while (tc>0)
            {
                now+=tc%10;
                tc/=10;
            }
            if (now==t) ans=min(ans,x1);
        }
        if ((x2>0)&&((long long)x2*x2+(long long)t*x2==n))
        {
            now=0;tc=x2;
            while (tc>0)
            {
                now+=tc%10;
                tc/=10;
            }
            if (now==t) ans=min(ans,x2);
        }
    }
    if (ans==maxlongint) cout<<-1<<endl; else cout<<ans<<endl;
    return 0;
}