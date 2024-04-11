#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

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

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> v(n), t(n);
    cin >> v >> t;
    ll buf = 0;
    multiset<ll> now;
    for (int i = 0; i < n; ++i) {
        now.insert(v[i] + buf);
        buf += t[i];
        ll here = 0;
        while (!now.empty() && *now.begin() <= buf) {
            here += *now.begin() - buf + t[i];
            now.erase(now.begin());
        }
        here += t[i] * now.size();
        cout << here << " ";
    }
    return 0;
}