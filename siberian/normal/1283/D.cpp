#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct segment{
    int l, r;
    segment() {}
    segment(int a, int b) {
        l = a, r = b;
    }
};

bool operator<(const segment & a, const segment & b) {
    return tie(a.r, b.l) < tie(b.r, a.l);
}

void recalc(vector<segment> & a) {
    for (auto &i : a)
        i.l--, i.r++;
    sort(all(a));
    vector<segment> b;
    for (auto i : a) {
        if (!b.empty() && b.back().r > i.l) {
            b[b.size() - 1].r = i.r;
        }
        else {
            b.push_back(i);
        }
    }
    a = b;
}

int n, m;
vector<int> x;

void read() {
    cin >> n >> m;
    x.resize(n);
    for (auto &i : x) {
        cin >> i;
    }
    sort(all(x));
}

ll ans;
vector<int> fans;

void run() {
    ans = 0;
    vector<segment> a;
    for (auto i : x) {
        a.push_back({i, i});
    }
    int add = 0;
    while (m) {
        recalc(a);
        set<int> can;
        for (auto i : a)
            can.insert(i.l), can.insert(i.r);

        /*cout << "a = " << endl;
        for (auto i : a)
            cout << i.l << " " << i.r << endl;
        cout << endl;*/
        add++;
        for (auto i : can) {
            if (m) {
                fans.push_back(i);
                ans += add;
                m--;
            }
        }
    }
}

void write() {
    sort(all(fans));
    cout << ans << endl;
    for (auto i : fans)
        cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}