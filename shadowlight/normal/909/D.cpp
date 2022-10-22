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
    int n = s.size();
    set <int> q;
    for (int i = 0; i < n; i++) {
        q.insert(i);
    }
    vector <int> a;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] != s[i - 1]) {
            a.push_back(i);
        } else if (i < n - 1 && s[i] != s[i + 1]) {
            a.push_back(i);
        }
    }
    vector <int> used(n, 0);
    int cnt = 0;
    while (a.size()) {
        for (int x : a) {
            used[x] = 0;
            q.erase(x);
        }
        vector <int> b;
        for (int x : a) {
            auto it1 = q.lower_bound(x);
            if (it1 == q.begin()) continue;
            it1--;
            auto it2 = q.upper_bound(x);
            if (it2 == q.end()) continue;
            if (s[*it1] != s[*it2]) {
                if (!used[*it1]) {
                    b.push_back(*it1);
                    used[*it1] = 1;
                }
                if (!used[*it2]) {
                    b.push_back(*it2);
                    used[*it2] = 1;
                }
            }
        }
        a = b;
        cnt++;
    }
    cout << cnt;
}