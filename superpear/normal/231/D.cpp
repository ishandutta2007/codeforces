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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int main()
{
    int x,y,z,x1,y1,z1,a1,a2,a3,a4,a5,a6,ans;
    cin>>x1>>y1>>z1;
    cin>>x>>y>>z;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    ans=0;
    if (y1<0) ans+=a1;
    if (y1>y) ans+=a2;
    if (z1<0) ans+=a3;
    if (z1>z) ans+=a4;
    if (x1<0) ans+=a5;
    if (x1>x) ans+=a6;
    cout<<ans<<endl;
    return 0;
}