#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

template<typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &item : a) {
        in >> item;
    }
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &item : a) {
        out << item << " ";
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
    for (auto &item : a) {
        out << item << "\n";
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << fixed << setprecision(11);
    int n;
    ll u;
    cin >> n >> u;
    vector<ll> a(n);
    cin >> a;
    double ans = -1;
    for (int i = 0; i < n; ++i) {
        ll pi = upper_bound(a.begin() + i, a.end(), a[i] + u) - a.begin() - 1;
        if (pi <= i + 1) continue;
        ans = max(ans, double(a[pi] - a[i + 1]) / double(a[pi] - a[i]));
    }
    if (ans == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}