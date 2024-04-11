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

int main()
{
    int n,a[1000];
    cin>>n;
    if (n%2==1) cout<<"-1"<<endl; else
    {
        for (int i=1;i<=n;i++) a[i]=i;
        for (int i=1;i<=n;i++) if (i%2==1) swap(a[i],a[i+1]);
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}