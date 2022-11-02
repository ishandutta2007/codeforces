#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10;
int n;
int in[MAXN];
int out[MAXN];

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> out[i];
        in[out[i]] = i;
    }
}

void run() {
    set<int> Full;
    for (int i = 1; i <= n; i++) {
        if (!in[i] && !out[i])
            Full.insert(i);
    }

    set<int> need;

    for (int i = 1; i <= n; i++) {
        if (!in[i] && out[i])
            need.insert(i);
    }

    while (!need.empty()) {
        int x = *need.begin();
        int y = x;
        need.erase(x);
        while (out[x])
            x = out[x];
        while (!Full.empty()) {
            out[x] = *Full.begin();
            Full.erase(Full.begin());
            x = out[x];
        }
        out[x] = y;
    }

    if (!Full.empty()) {
        int x = *Full.begin();
        Full.erase(Full.begin());
        int y = x;
        while (!Full.empty()) {
            out[x] = *Full.begin();
            Full.erase(Full.begin());
            x = out[x];
        }
        out[x] = y;
    }
}

void write() {
    for (int i = 1; i <= n; i++)
        cout << out[i] << " ";
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