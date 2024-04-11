#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 3e5 + 7;
const double EPS = 1e-8;

vector <int> f(MAXN, -1);
vector <int> pr;

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (f[i] == -1) {
            pr.push_back(i);
            f[i] = pr.size() - 1;
        }
        for (int j = 0; (j <= f[i] && pr[j] * i < MAXN); j++) {
            f[pr[j] * i] = j;
        }
    }
}

vector <int> fact(int x) {
    int last = -1;
    vector <int> a;
    while (x != 1) {
        if (pr[f[x]] != last) {
            a.push_back(pr[f[x]]);
        }
        last = pr[f[x]];
        x /= pr[f[x]];
    }
    return a;
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
    init();
    int n;
    cin >> n;
    vector <int> cnt(MAXN, 0);
    int g = 0;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        g = __gcd(g, x);
        cnt[x]++;
    }
    vector <int> del(MAXN, 0);
    for (int i = MAXN - 1; i >= 1; i--) {
        for (int j = 1; i * j < MAXN; j++) {
            del[i] += cnt[i * j];
        }
    }
    vector <int> cnta(MAXN, 0);
    for (int i = MAXN - 1; i >= 2; i--) {
        auto mas = fact(i);
        int N = 1 << (int) mas.size();
        int t = 1;
        for (int x : mas) {
            t *= x;
        }
        if (t != i) continue;
        int now = 0;
        for (int mask = 0; mask < N; mask++) {
            int cnt = __builtin_popcount(mask);
            int d = 1;
            for (int j = 0; j < mas.size(); j++) {
                if (mask & (1 << j)) {
                    d *= mas[j];
                }
            }
            now += (cnt % 2 ? -1 : 1) * del[d];
        }
        cnta[i] = now;
    }
    if (g != 1) {
        cout << -1;
        return 0;
    }
    int res = INF;
    vector <vector <vector <int> > > unmasks(7);
    for (int i = 1; i <= 6; i++) {
        unmasks[i].resize(1 << i);
        for (int mask = 0; mask < (1 << i); mask++) {
            for (int mask1 = 0; mask1 < (1 << i); mask1++) {
                if (mask1 & mask) continue;
                unmasks[i][mask].push_back(mask1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        vector <int> mas = fact(a[i]);
        if (!mas.size()) {
            res = 1;
            break;
        }
//        for (int x : mas) {
//            cout << x << " ";
//        }
//        cout << "\n";
        int N = 1 << (int) mas.size();
        vector <int> nums(N, 0);
        for (int mask = 0; mask < N; mask++) {
            int d = 1;
            for (int j = 0; j < (int) mas.size(); j++) {
                if (mask & (1 << j)) {
                    d *= mas[j];
                }
            }
            nums[mask] = d;
        }
        vector <int> dp(N, INF);
        dp[0] = 0;
        //cout << "MASKS\n";
        for (int mask = 0; mask < N; mask++) {
            //cout << mask << " " << dp[mask] << "\n";
            for (int mask1 : unmasks[mas.size()][mask]) {
                //cout << "MASK1 " << mask1 << " " << nums[mask1] << " " << cnta[nums[mask]] << "\n";
                if (!cnta[nums[mask1]]) continue;
                dp[mask | mask1] = min(dp[mask | mask1], dp[mask] + 1);
            }
        }
        res = min(res, dp[N - 1] + 1);
    }
    cout << res;
}