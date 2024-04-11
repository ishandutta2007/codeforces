//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

int go(string s, char a, char b) {
    int n = s.length();
    if (a == '0' && b == '0') {
        vector<int> ps;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') ps.push_back(i);
        }
        if ((int)ps.size() < 2) return INF;
        return (n - 1) - ps[0] + (n - 2) - ps[1];
    }

    int pa = -1;
    int pb = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == a && pa == -1) pa = i;
        if (s[i] == b && pb == -1) pb = i;
    }
    if (pa == -1 || pb == -1) return INF;

    int ans = 0;
    if (pb < pa) {
        swap(pa, pb);
        ans++;
    }
    ans += (n - 1) - pb + (n - 2) - pa;
    int num = 0;
    int ok = false;
    for (int i = 0; i < n; i++) {
        if (i == pa || i == pb) continue;
        if (s[i] == '0' && !ok) num++;
        else ok = true;
    }
    if (!ok && num > 0) return INF;
    ans += num;
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int ans = min(min(go(s, '2', '5'), go(s, '5', '0')), min(go(s, '7', '5'), go(s, '0', '0')));
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    //solve();
    //solve();
#endif
    solve();
    return 0;
}