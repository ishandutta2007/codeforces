#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
bool isprime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        edges.push_back({i, (i + 1) % n});
    }
    int k = n;
    int p = 0;
    int shag = n / 2;
    while (!isprime(k)) {
        k++;
        edges.push_back({p, p + shag});
        p++;
    }
    cout << edges.size() << endl;
    for (auto [l, r] : edges)
        cout << l + 1 << ' ' << r + 1 << '\n';
}