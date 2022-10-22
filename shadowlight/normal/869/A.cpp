#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 4e6 + 7;
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
    vector <bool> exist(MAXN, false);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        exist[a[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        exist[b[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (exist[a[i] ^ b[j]]) {
                cnt++;
            }
        }
    }
    cout << (cnt % 2 == 0 ? "Karen" : "Koyomi");
}