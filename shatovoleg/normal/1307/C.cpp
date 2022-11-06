#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>
#define pb push_back
#define kek pop_back
#define mp make_pair
#define int ll

const int INF = (is_same<int, ll>::value ? 1e18L + 666 : 1e9L + 666);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    string s;
    cin >> s;
    int n = len(s);
    vector<vector<int>> cnt(26, vector<int>(26, 0));
    vector<int> cur(26, 0);
    for (auto &x : s) {
        for (int i = 0; i < 26; ++i) {
            cnt[i][x - 'a'] += cur[i];
        }
        ++cur[x - 'a'];
    }
    int ans = *max_element(all(cur));
    for (auto &x : cnt) {
        cmax(ans, *max_element(all(x)));
    }
    cout << ans << endl;
}