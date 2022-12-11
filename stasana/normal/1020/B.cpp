#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

vector<int> to;
vector<int> used;

int dfs(int v) {
    if (used[v] == 1) {
        return v;
    }
    used[v] = 1;
    return dfs(to[v]);
}

int main() {
    start();

    int n;
    cin >> n;
    to.resize(n);
    for (int i = 0; i < n; ++i) {
        to[i] = input<int>() - 1;
    }
    for (int i = 0; i < n; ++i) {
        used.clear();
        used.resize(n);
        cout << dfs(i) + 1 << " ";
    }

    return 0;
}