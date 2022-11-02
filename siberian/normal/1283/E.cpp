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
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
}

int ans_min, ans_max;

void solve_min() {
    vector<int> x;
    for (int i = 1; i <= n; i++) {
        if (a[i]) x.push_back(i);
    }
    ans_min = 0;
    int pos = 0;
    while (pos < x.size()) {
        if (pos == x.size() - 1) {
            ans_min++;
            break;
        }
        if (pos == x.size() - 2) {
            ans_min++;
            if (x[pos + 1] > x[pos] + 2) {
                ans_min++;
            } 
            break;
        }
        if (x[pos + 2] > x[pos] + 2) {
            if (x[pos + 1] > x[pos] + 2) {
                ans_min++;
                pos++;
            }
            else {
                pos += 2;
                ans_min++;
            }
        }
        else {
            pos += 3;
            ans_min++;
        }
    }
}

bool used[MAXN];

void solve_max() {
    for (int i = 1; i <= n; i++) {
        if (!a[i]) continue;
        if (!used[i - 1]) {
            a[i]--;
            used[i - 1] = true;
        }
        if (!a[i]) continue;
        if (!used[i]) {
            a[i]--;
            used[i] = true;
        }
        if (!a[i]) continue;
        if (!used[i + 1]) {
            a[i]--;
            used[i + 1] = true;
        }
    }
    ans_max = 0;
    for (int i = 0; i <= n + 1; i++)
        ans_max += used[i];
}

void run() {
    solve_min();
    solve_max();
}

void write() {
    cout << ans_min << " " << ans_max << endl;
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