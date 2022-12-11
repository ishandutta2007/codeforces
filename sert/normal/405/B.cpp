#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

ll n, ans;
string s;
ll pr = -1;
ll tp = -1;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') continue;
        if (s[i] == 'R')
            ans += i - pr - 1;
        if (s[i] == 'L')
            if ((i - pr) % 2 == 0 && pr != -1)
                ans++;
        pr = i;
    }
    if (s[pr] == 'L')
        ans += n - pr - 1;
    if (pr == -1)
        ans = n;

    cout << ans;

    return 0;
}