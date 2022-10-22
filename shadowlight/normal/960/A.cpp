#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    string s;
    cin >> s;
    int tp = 0;
    vector <int> cnt(3, 0);
    for (char c : s) {
        int k = c - 'a';
        if (k < tp || k > tp + 1) {
            cout << "NO\n";
            return 0;
        }
        cnt[k]++;
        tp = k;
    }
    if (!cnt[0] || !cnt[1]) {
        cout << "NO\n";
        return 0;
    }
    if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}