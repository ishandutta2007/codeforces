#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0, c = 0;
    int pa = 0, pb = 0, pc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a++;
            pa = i;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            b++;
            pb = i;
        } else {
            c++;
            pc = i;
        }
    }
    if (a == n || b == n || c == n) {
        if (a == n) {
            s[0] = 'a';
            s[1] = 'A';
        } else if (b == n) {
            s[0] = 'A';
            s[1] = '0';
        } else if (c == n) {
            s[0] = 'a';
            s[1] = '0';
        }
        cout << s << "\n";
        return;
    }
    if (!a) {
        if (b > 1) {
            s[pb] = '0';
        } else {
            s[pc] = '0';
        }
    } else if (!b) {
        if (a > 1) {
            s[pa] = 'a';
        } else {
            s[pc] = 'a';
        }
    } else if (!c) {
        if (a > 1) {
            s[pa] = 'A';
        } else {
            s[pb] = 'A';
        }
    }
    cout << s << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}