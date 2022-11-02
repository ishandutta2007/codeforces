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

int n,e,last,ans,a[10000],b[10000];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    e=0;
    last=0;
    for (int i=1;i<=n;i++)
        if (a[i]<0)
        {
            e++;
            if (e==3)
            {
                ++ans;
                b[ans]=i-1-last;
                last=i-1;
                e=1;
            }
        }
    ++ans;
    b[ans]=n-last;
    cout<<ans<<endl;
    for (int i=1;i<=ans;i++) cout<<b[i]<<" ";cout<<endl;

    return 0;
}