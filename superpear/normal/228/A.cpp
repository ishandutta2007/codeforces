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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int a,b,c,d,ans;
int main()
{
    scanf("%d %d %d %d",&a,&b,&c,&d);
    ans=0;
    if (b==a) ++ans;
    if ((c==a)||(c==b)) ++ans;
    if ((d==a)||(d==b)||(d==c)) ++ans;
    cout<<ans<<endl;

    return 0;
}