#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n, q;

void read() {
    cin >> n >> q;
}

multiset<int> len;
set<int> setik;

void add(int x) {
    auto it = setik.lower_bound(x);
    if (it != setik.end() && it != setik.begin()) {
        int R = *it;
        int L = *(--it);
        len.erase(len.find(R - L));
    }
    setik.insert(x);
    it = setik.find(x);
    ++it;
    if (it != setik.end()) {
        len.insert(*it - x);
    }
    it = setik.find(x);
    if (it != setik.begin()) {
        --it;
        len.insert(x - *it);
    }
}

void del(int x) {
    auto it = setik.find(x);
    ++it;
    if (it != setik.end()) {
        len.erase(len.find(*it - x));
    }
    it = setik.find(x);
    if (it != setik.begin()) {
        --it;
        len.erase(len.find(x - *it));
    }
    setik.erase(x);
    it = setik.lower_bound(x);
    if (it == setik.end()) return;
    if (it == setik.begin()) return;
    int R = *it;
    int L = *(--it);
    len.insert(R - L);
}

int getAns() {
    if (setik.size() <= 2) return 0;
    return *(--setik.end()) - *(setik.begin()) - *(--len.end());
}

void run() {
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    cout << getAns() << "\n";
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            add(x);
        } else {
            del(x);
        }
        cout << getAns() << "\n";
    }
}

void write() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}