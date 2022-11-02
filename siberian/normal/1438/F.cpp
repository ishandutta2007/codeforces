#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int query(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    int ans;
    cin >> ans;
    return ans - 1; 
}

void outAns(int ans) {
    cout << "! " << ans + 1 << endl;
    exit(0);
}

mt19937 rnd(time(0));

vector<int> cnt;
int h, n;

int getV() {
    return (rnd() % n + n) % n;
}

void relax() {
    while (true) {
        int a = getV();
        int b = getV();
        int c = getV();
        if (a == b || a == c || b == c) continue; 
        cnt[query(a, b, c)]++;
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    cin >> h;
    n = (1 << h) - 1;
    cnt.assign(n, 0);
    const int IT = 400 + 2;
    for (int it = 0; it < IT; ++it) {
        relax();
    }
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&] (int a, int b) {
        return cnt[a] > cnt[b];
    });
    int a = order[0];
    int b = order[1];
    order.erase(order.begin());
    order.erase(order.begin());
    shuffle(all(order), rnd);
    for (auto c : order) {
        if (query(a, b, c) == c) {
            outAns(c);
        }
    }
    assert(false);
    return 0;
}