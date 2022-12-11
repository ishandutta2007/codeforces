#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll a, b, sg;
ll ans;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> a >> b;
    ans = 0;
    while (a > 0) {
         a--;
         sg++;
         if (sg >= b) {
            sg -= b;
            a++;
         }
         ans++;
    }
    cout << ans;

    return 0;
}