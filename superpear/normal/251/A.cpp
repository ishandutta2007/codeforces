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

int n,d,a[1000000];
int main()
{
    int left,right,mid,t;

    scanf("%d %d",&n,&d);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    LL ans=0;
    for (int i=1;i<=n;i++)
    {
        left=i+1;right=n;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (a[mid]-a[i]<=d) left=mid+1; else right=mid-1;
        }
        t=(right-i);
        ans+=(LL)t*(t-1)/2;
    }
    cout<<ans<<endl;

    return 0;
}