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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

double vp,vd,t,f,c,nowp,last,qo;
int main()
{
    cin>>vp>>vd>>t>>f>>c;
    if (vd<=vp)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        nowp=vp*t;
        last=0;
        for (int i=0;i<=1000000;i++)
        {
            if (nowp>=c)
            {
                cout<<max(0,i-1)<<endl;
                return 0;
            }
            nowp+=last*vp;
            qo=nowp/(vd-vp);
            nowp+=qo*vp;
            last=qo+f;
        }
    }

    return 0;
}