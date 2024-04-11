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
ll x, d;

int main()
{
    cin >> x >> d;
    vector<ll> ans;
    for (ll i = 29; i >= 0; i--) {
        if (x & (1ll<<i)) {
            for (int j = 1; j <= i; j++)
                ans.push_back(d * 2 * i + 1);
            ans.push_back(d * 2 * i + d + 1);
        }
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}