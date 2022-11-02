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

int n,x,y,c;

bool ok(int x,int y,int s,int c)
{
    if ((n>=200000)&&((LL)s*s>=(LL)c*10)) return true;
    LL ans=0;
    int lc,rc;
    for (int i=x-s;i<=x+s;i++)
        if ((i>0)&&(i<=n))
        {
            lc=y-(s-abs(i-x));
            rc=y+(s-abs(i-x));
            if (lc<1) lc=1;
            if (rc>n) rc=n;
            ans+=(LL)(rc-lc+1);
        }
    return ans>=c;
}

int main()
{
    scanf("%d %d %d %d",&n,&x,&y,&c);
    int left,right,mid;
    left=0;right=n*2;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (ok(x,y,mid,c)) right=mid-1; else left=mid+1;
    }
    printf("%d\n",left);

    return 0;
}