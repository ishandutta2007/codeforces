#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(a) a.begin(), a.end()

using namespace std;

template<typename T1, typename T2> inline void chkmin(T1& x, const T2& y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1& x, const T2& y) {if (x < y) x = y;}

#define int ll

int n, k;
vector<int> a;

void read() {
    cin >> n >> k;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
    }
}

int calc(int val, int cnt) {
    int L = val / cnt;
    int R = val / cnt + 1;
    return L * L * (cnt - val % cnt) + R * R * (val % cnt);
}

int getNxt(int val, int nowCnt) {
    return calc(val, nowCnt + 1) - calc(val, nowCnt);
}

vector<int> cnt;
int ans;
set<pair<int, int>> fupd;

void build() {
    cnt.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] != 1) {
            fupd.insert({getNxt(a[i], 1), i});
        }
        ans += calc(a[i], 1);
    }
    //cout << "ans = " << ans << endl;
}

void upd() {
    auto it = *fupd.begin();
    fupd.erase(fupd.begin());
    int ind = it.second;
    ans -= calc(a[ind], cnt[ind]);
    cnt[ind]++;
    ans += calc(a[ind], cnt[ind]);
    if (cnt[ind] != a[ind]) {
        fupd.insert({getNxt(a[ind], cnt[ind]), ind});
    }
}

void run() {
    build();
    for (int it = 0; it < k - n; ++it) {
        upd();
        /*cout << "fupd = " << endl;
        for (auto x : fupd) {
            cout << x.first << " " << x.second << endl;
        }*/
    }
    /*cout << "cnt = " << endl;
    for (auto i : cnt) {
        cout << i << " ";
    }
    cout << endl;*/
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    read();
    run();
    write();
    return 0;
}