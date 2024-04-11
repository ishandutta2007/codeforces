#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz];

int main()
{
    double h,l;
    cin >> h >> l;
    printf("%.10f\n", (h*h+l*l)/(2.0*h)-h);
}