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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int maxk = -1, mink = INF, pos = -1;
    set <int> all;
    for (int i = 0; i < n; i++) {
        int k = s[i] - 'a';
        maxk = max(maxk, k);
        mink = min(mink, k);
        all.insert(k);
    }
    if (k > n) {
        cout << s;
        for (int i = 0; i < k - n; i++) {
            cout << (char) (mink + 'a');
        }
        return 0;
    }
    for (int i = min(k - 1, n - 1); i >= 0; i--) {
        if (s[i] - 'a' != maxk) {
            pos = i;
            break;
        }
    }
    assert(pos != -1);
    int v = *all.upper_bound(s[pos] - 'a');
    for (int i = 0; i < pos; i++) {
        cout << s[i];
    }
    cout << (char) (v + 'a');
    for (int i = pos + 1; i < k; i++) {
        cout << (char) (mink + 'a');
    }
}