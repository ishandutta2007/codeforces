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
    for (int i = 0; i < n - 2; i++) {
        vector <char> t = {s[i], s[i + 1], s[i + 2]};
        sort(t.begin(), t.end());
        if (t[0] == 'A' && t[1] == 'B' && t[2] == 'C') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}