#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

int getOr(int i, int j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int getAnd(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int getSum(int i, int j) {
    return getOr(i, j) + getAnd(i, j);
}

int outAns(int a) {
    cout << "finish " << a << endl;
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n, k;
    cin >> n >> k;
    int x = getSum(0, 1);
    int y = getSum(1, 2);
    int z = getSum(0, 2);
    int a1 = (x + y + z) / 2 - y;
    int a2 = (x + y + z) / 2 - z;
    int a3 = (x + y + z) / 2 - x;
    vector<int> a = {a1, a2, a3};
    for (int i = 3; i < n; ++i) {
        int ai = getSum(i - 1, i) - a.back();
        a.push_back(ai);
    }
    sort(all(a));
    outAns(a[k - 1]);
    return 0;
}