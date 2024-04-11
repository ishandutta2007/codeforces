#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 5007;
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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> c(n, 0);
    vector <int> cnt(k, 0);
    vector <vector <int> > used(MAXN, vector <int> (k, 0));
    for (int i = 0; i < n; i++) {
        int now = 0;
        while (now < k && used[a[i]][now]) {
            now++;
        }
        if (now == k) {
            cout << "NO\n";
            return 0;
        }
        c[i] = now;
        used[a[i]][now] = 1;
        cnt[now]++;
    }
    for (int i = 0; i < k; i++) {
        if (!cnt[i]) {
            for (int j = 0; j < n; j++) {
                if (cnt[c[j]] > 1) {
                    cnt[c[j]]--;
                    cnt[i]++;
                    c[j] = i;
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << c[i] + 1 << " ";
    }

}