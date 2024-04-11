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
    int k, n, m;
    cin >> n >> m >> k;
    int l = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    vector <int> exist(n, 1);
    sort(a.begin(), a.end());
    int res = 0;
    for (int r = 0; r < n; r++) {
        cnt++;
        while (a[r] - a[l] >= m) {
            if (exist[l]) {
                cnt--;
            }
            l++;
        }
        if (cnt == k) {
            cnt--;
            exist[r] = 0;
            res++;
        }
    }
    cout << res;
}