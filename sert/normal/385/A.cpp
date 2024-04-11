#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 2014;

void fail() {
    cout << "NO\n";
    exit(0);
}


int n, ans, t, pr, c;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> c;
    cin >> t;

    for (int i = 1; i < n; i++) {
        pr = t;
        cin >> t;
        if (ans < pr - t - c) {
            ans = pr - t - c;
        }
    }

    cout << ans;

    return 0;
}