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
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    set <pair <int, int> > q;
    set <pair <int, int> > erased;
    vector <vector <pair <int, int> > > data(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < (int) s.size(); j++) {
            int now = 0;
            for (int k = j; k < (int) s.size(); k++) {
                now *= 10;
                now += (s[k] - '0');
                pair <int, int> p = {now, k - j + 1};
                data[i].push_back(p);
                if (erased.find(p) != erased.end()) continue;
                if (q.find(p) != q.end()) {
                    q.erase(p);
                    erased.insert(p);
                }
            }
        }
        for (auto p : data[i]) {
            q.insert(p);
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = 0, sz = INF;
        for (auto p : data[i]) {
            if (erased.find(p) != erased.end()) continue;
            if (sz > p.second) {
                sz = p.second;
                ans = p.first;
            }
        }
        string s = "";
        while (ans) {
            s += (char) (ans % 10 + '0');
            ans /= 10;
        }
        while (s.size() != sz) {
            s += "0";
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}