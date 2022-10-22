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
    int n;
    cin >> n;
    vector <int> pos(n, 0);
    int now = 0;
    vector <bool> del(n, false);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (del[x]) {
            cout << "0 ";
            continue;
        }
        int res = 0;
        while (a[now] != x) {
            res++;
            del[a[now]] = true;
            now++;
        }
        cout << res + 1 << " ";
        del[a[now]] = true;
        now++;
    }
}