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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    string name = "";
    name += 'z' + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string res = s.substr(0, i + 1) + t.substr(0, j + 1);
            if (res < name) {
                name = res;
            }
        }
    }
    cout << name;
}