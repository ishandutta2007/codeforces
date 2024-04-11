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
    set <vector <int> > q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector <int> now(Q, 0);
        for (char c : s) {
            now[c - 'a'] = 1;
        }
        q.insert(now);
    }
    cout << q.size() << "\n";
}