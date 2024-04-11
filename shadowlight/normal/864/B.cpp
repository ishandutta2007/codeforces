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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <bool> used(Q, 0);
    int cnt = 0;
    int maxk = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            used.assign(Q, 0);
            maxk = max(maxk, cnt);
            cnt = 0;
            continue;
        }
        if (!used[c - 'a']) {
            used[c - 'a'] = 1;
            cnt++;
        }
    }
    maxk = max(maxk, cnt);
    cout << maxk;
}