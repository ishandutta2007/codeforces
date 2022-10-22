#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(4), b(4);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    a[3] = a[0];
    for (int i = 0; i < 3; ++i) {
        cin >> b[i];
    }
    b[3] = b[0];

    int win = 0;
    int los = 0;
    for (int i = 0; i < 3; ++i) {
        win += min(a[i], b[i + 1]);
        los += max(0, a[i] - n + b[i + 1]);
    }

    cout << los << " " << win << "\n";

    return 0;
}