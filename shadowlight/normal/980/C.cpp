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
    vector <int> len(256, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (len[x]) {
            cout << x - len[x] + 1 << " ";
            continue;
        }
        int j;
        for (j = x; j > -1; j--) {
            if (max(len[j], 1) + x - j > k) break;
        }
        j++;
        for (int l = j; l <= x; l++) {
            len[l] = l - j + 1;
        }
        cout << j << " ";
    }
}