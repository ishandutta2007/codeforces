#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;
const double pi=acos(-1.0);

int main()
{
    double n,r,R,x;
    cin >> n >> r;
    x=pi/n;
    double ans=r*sin(x);
    ans/=1.0-sin(x);
    printf("%.10f\n", ans);
}