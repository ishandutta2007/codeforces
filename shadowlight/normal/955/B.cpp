#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int Q = 31;

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
    vector <int> cnt(Q, 0);
    int all = 0;
    for (char c : s) {
        cnt[c - 'a']++;
    }
    for (int i = 0; i < Q; i++) {
        if (cnt[i]) {
            all++;
        }
    }
    if (all > 4 || all < 2) {
        cout << "No\n";
        return 0;
    }
    if (all == 4) {
        cout << "Yes\n";
        return 0;
    }
    if (all == 2) {
        for (int i = 0; i < Q; i++) {
            if (cnt[i] == 1) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
        return 0;
    }
    if (s.size() == 3) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}