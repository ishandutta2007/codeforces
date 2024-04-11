#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int k2, k3, k5, k6;
ll res = 0;
int main()
{
    cin >> k2 >> k3 >> k5 >> k6;
    int tmp = min(min(k2, k5), k6);
    k2 -= tmp, k5 -= tmp, k6 -= tmp;
    res += (ll)tmp * 256;
    res += min(k2, k3) * (ll)32;
    cout << res << endl;
}