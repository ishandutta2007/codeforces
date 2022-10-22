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
    int N = 1 << k;
    vector <int> mask(N, 0);
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (!x) {
                now += (1 << j);
            }
        }
        mask[now]++;
    }
    if (mask[N - 1]) {
        cout << "Yes\n";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int mask1 = N - 1 - i;
        for (int j = 0; j < N; j++) {
            if ((mask1 | j) > j) continue;
            //cout << i << " " << j << "\n";
            if (mask[i] && mask[j]) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";

}