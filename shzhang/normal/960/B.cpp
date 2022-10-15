#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ll long long

int n;
ll a[1005];
ll b[1005];
int k1, k2;

ll absolute(ll v)
{
    return v < 0 ? -v : v;
}

int main()
{
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= k1+k2; i++) {
        int choice = 1;
        for (int j = 1; j <= n; j++) {
            if (absolute(a[j] - b[j]) > absolute(a[choice] - b[choice])) {
                choice = j;
            }
        }
        if (a[choice] > b[choice]) {
            a[choice]--;
        } else {
            a[choice]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (a[i] - b[i]) * (a[i] - b[i]);
    }
    cout << ans;
    return 0;
}