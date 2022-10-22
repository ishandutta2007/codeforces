#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    string s;
    cin >> s;
    int n = s.size();
    vector <int> cnta(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            cnta[i + 1]++;
        }
        cnta[i + 1] += cnta[i];
    }
    int ans = cnta[n];
    for (int l = 1; l <= n; l++) {
        if (s[l - 1] == 'a') continue;
        for (int r = l; r <= n; r++) {
            if (s[r - 1] == 'a') continue;
            int now = ((r - l + 1) - (cnta[r] - cnta[l - 1])) + cnta[l - 1] + cnta[n] - cnta[r];
            ans = max(ans, now);
        }
    }
    cout << ans;
}