#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int NICO = 60000 + 10;
int x[NICO], v[NICO], n;
int ok(double p)
{
    double a = 1, b = 1e9;
    for(int i=1;i<=n;i++)
    {
        a = max(a, x[i] - v[i] * p);
        b = min(b, x[i] + v[i] * p);
    }
    if(a < b) return 1;
    return 0;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> v[i];
    }
    double l = 0, r = 1e9;
    for(int i=1;i<=100;i++)
    {
        double mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid;
    } 
    printf("%.10f\n", (l+r)/2);
}