#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e3 + 34;
const ll md = (ll)1e9 + 7;

int sum(int x) {
    return (x < 10 ? x : x % 10 + sum(x / 10));
}

int main() {
    init();
    int n;
    cin >> n;
    vector <int> ans;

    for (int i = max(0, n - 999); i <= n; i++) {
        if (i + sum(i) == n)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << " ";


    return 0;
}