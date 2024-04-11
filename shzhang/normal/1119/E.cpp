#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

#define ll long long

int n;
ll a[300005];
ll psum[300005];
ll s[300005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i];
    for (int i = 1; i <= n; i++) {
        s[i] = min(psum[i] / 3LL, s[i-1] + a[i]/2LL);
    }
    cout << s[n];
    return 0;
}