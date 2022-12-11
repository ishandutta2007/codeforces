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


int n, m, k, q, ans;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> q;
        if (q == 1)
            if (m == 0)
                ans++;
            else
                m--;
        else
            if (k == 0)
                if (m == 0)
                    ans++;
                else
                    m--;
            else
                k--;
    }

    cout << ans;

    return 0;
}