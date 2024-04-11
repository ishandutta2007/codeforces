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
    int n,a,b,c,ans=0,s;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        s=a+b+c;
        if (s>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}