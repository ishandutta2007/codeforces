#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int gcd(int a, int b) {
    if (!a) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    vector <int> a(n);
    int now = 0;
    vector <bool> exist(MAXN, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        now = gcd(now, a[i]);
        exist[a[i]] = 1;
    }
    if (now != a[0]) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(a[i]);
        ans.push_back(a[0]);
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
}