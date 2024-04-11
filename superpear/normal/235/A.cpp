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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

long long gcd(long long a,long long b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    long long e=gcd(a,b);
    return a/e*b;
}

int main()
{
    int n;
    cin>>n;
    long long ans=0;
    int p=max(1,n-200);
    for (int i=n;i>=p;i--)
        for (int j=n;j>=p;j--)
            for (int k=n;k>=p;k--)
                ans=max(ans,lcm(lcm(i,j),k));
    cout<<ans<<endl;
    return 0;
}