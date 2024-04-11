#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 40;
const int K = 20;
int mod, n;
vector <int> a;

void force(int sum, int now, set <int> &can, int s) {
    if (now == K + s) {
        can.insert(sum);
        return;
    }
    force((sum + a[now]) % mod, now + 1, can, s);
    force(sum, now + 1, can, s);
}

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
    cin >> n >> mod;
    a.resize(N, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <int> alla, allb;
    force(0, 0, alla, 0);
    force(0, K, allb, K);
    int ans = 0;
    for (int x : allb) {
        int k = mod - x - 1;
        auto it = alla.upper_bound(k);
        if (it == alla.begin()) {
            ans = max(ans, (x + *it) % mod);
            continue;
        }
        it--;
        ans = max(ans, (x + *it) % mod);
    }
    cout << ans;
}