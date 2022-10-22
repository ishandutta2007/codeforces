#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000007;

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        que.push(i);
    }

    while (que.size() > 1) {
        vector<int> v(2);
        vector<int> ans(2);
        for (int i = 0; i < 2; ++i) {
            v[i] = que.front();
            que.pop();
        }
        for (int i = 0; i < 2; ++i) {
            cout << "? " << v[i] << " " << v[1 - i] << endl;
            cin >> ans[i];
        }
        if (ans[0] < ans[1]) {
            swap(ans[0], ans[1]);
            swap(v[0], v[1]);
        }
        a[v[0] - 1] = ans[0];
        que.push(v[1]);
    }
    a[que.front() - 1] = n;

    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    int rez;
    cin >> rez;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}