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
    vector <int> cnt(n + 1, 0);
    vector <int> cntd(10, -1);
    vector <vector <int> > digits(n + 1);
    digits[0] = cntd;
    for (int i = 0; i < n; i++) {
        int k = s[i] - '0';
        cntd[k] *= -1;
        cnt[i + 1] = cnt[i] + cntd[k];
        digits[i + 1] = cntd;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!i && s[i] == '1') continue;
        if (s[i] == '0') continue;
        if ((n - i - cnt[i]) % 2) continue;
        if (n - i < cnt[i]) continue;
        int val = -1;
        for (int j = s[i] - '0' - 1; j >= 0; j--) {
            if (digits[i][j] == 1) {
                val = j;
                break;
            }
        }
        if (val == -1 && n - i == cnt[i]) {
            continue;
        }
        int now = cnt[i];
        vector <int> dig = digits[i];
        if (n - i == now) {
            s[i] = (char) (val + '0');
            dig[val] *= -1;
            now--;
        } else {
            s[i]--;
            dig[s[i] - '0'] *= -1;
            now += dig[s[i] - '0'];
        }
        for (int j = i + 1; j < n; j++) {
            if (n - j == now) {
                int val = -1;
                for (int j = 9; j >= 0; j--) {
                    if (dig[j] == 1) {
                        val = j;
                        break;
                    }
                }
                s[j] = (char) (val + '0');
                dig[val] = -1;
                now--;
            } else {
                s[j] = '9';
                dig[9] *= -1;
                now += dig[9];
            }
        }
        cout << s << "\n";
        return;
    }
    for (int i = 0; i < n - 2; i++) {
        cout << 9;
    }
    cout << "\n";
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
}