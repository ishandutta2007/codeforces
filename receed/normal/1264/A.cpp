#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n), q;
        rep(i, n) {
            cin >> a[i];
            if (i == 0 || a[i - 1] != a[i])
                q.push_back(1);
            else
                q.back()++;
        }
        int pos = 1, s1 = 0, s2 = 0;
        while (pos < q.size() && s1 <= q[0])
            s1 += q[pos++];
        while (pos < q.size() && s2 <= q[0])
            s2 += q[pos++];
        while (pos < q.size() && q[0] + s1 + s2 + q[pos] <= n / 2)
            s2 += q[pos++];
        if (s1 <= q[0] || s2 <= q[0] || s1 + s2 + q[0] > n / 2 || s1 == 0 || s2 == 0)
            cout << "0 0 0\n";
        else
            cout << q[0] << ' ' << s1 << ' ' << s2 << '\n';
    }
}