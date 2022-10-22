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
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < n && s[l] != '[') {
        l++;
    }
    while (l < n && s[l] != ':') {
        l++;
    }
    l++;
    while (r >= 0 && s[r] != ']') {
        r--;
    }
    while (r >= 0 && s[r] != ':') {
        r--;
    }
    r--;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '|') {
            cnt++;
        }
    }
    if (l - 1 > r) {
        cout << "-1\n";
        return 0;
    }
    cout << cnt + 4;
}