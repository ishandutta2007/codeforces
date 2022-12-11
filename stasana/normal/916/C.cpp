#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

struct Edge {
    int v, w, cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    int res = 2;
    if  (m == 1) {
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 2 << " " << 2;
        return 0;
    }
    vector<Edge> a;
    a.push_back({1, n, 2});
    for (int i = 1; i < n - 2; ++i) {
        a.push_back({1, i + 1, 1});
        ++res;
    }
    int cost = 1;
    while (!isPrime(res + cost)) {
        ++cost;
    }
    a.push_back({1, n - 1, cost});
    res += cost;
    m -= n - 1;
    for (int i = 2; i <= n; ++i) {
        if (m == 0) {
            break;
        }
        for (int j = i + 1; j <= n; ++j) {
            if (m == 0) {
                break;
            }
            a.push_back({i, j, 1000000000});
            --m;
        }
    }
    cout << 2 << " " << res << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].v << " " << a[i].w << " " << a[i].cost << endl;
    }
    return 0;
}