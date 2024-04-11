#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> cnt(3, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (cnt[c] <= n / 3) continue;
        for (int j = 0; j < c; j++) {
            if (cnt[j] < n / 3) {
                cnt[j]++;
                cnt[c]--;
                s[i] = (char) (j + '0');
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - '0';
        if (cnt[c] <= n / 3) continue;
        for (int j = 2; j > c; j--) {
            if (cnt[j] < n / 3) {
                cnt[j]++;
                cnt[c]--;
                s[i] = (char) (j + '0');
                break;
            }
        }
    }
    cout << s;
}