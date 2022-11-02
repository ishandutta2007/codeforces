#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mn = 1e9;
        for (auto& i : a) {
            cin >> i;
            mn = min(mn, i);
        }
        int cnt = 0;
        for (auto i : a)
            if (i == mn)
                cnt++;
        cout << n - cnt << '\n';
    }
}