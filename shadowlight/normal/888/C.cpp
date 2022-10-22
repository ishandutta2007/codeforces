#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

string s;
int n;

bool check(int k) {
    vector <int> cnt(Q, 0);
    vector <bool> good(Q, true);
    for (int i = 0; i < k; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < Q; i++) {
        if (!cnt[i]) {
            good[i] = false;
        }
    }
    for (int i = k; i < n; i++) {
        cnt[s[i - k] - 'a']--;
        cnt[s[i] - 'a']++;
        if (!cnt[s[i - k] - 'a']) {
            good[s[i - k] - 'a'] = false;
        }
    }
    for (int i = 0; i < Q; i++) {
        if (good[i]) {
            return true;
        }
    }
    return false;
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
    #endif // MY'
    cin >> s;
    n = s.size();
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}