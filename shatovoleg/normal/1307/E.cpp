#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pii pair<int, int>
#define pb push_back
#define kek pop_back
#define mp make_pair
#define int ll

const int INF = (is_same<int, ll>::value ? 1e18L + 666 : 1e9L + 666);

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

const int mod = 1e9 + 7;

void add(pii &a, const pii &b) {
    if (a.first != b.first) {
        cmax(a, b);
        return;
    }
    a.second += b.second;
    if (a.second >= mod) {
        a.second -= mod;
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> tot_cnt(n);
    for (auto &x : a) {
        cin >> x;
        --x;
        ++tot_cnt[x];
    }
    vector<vector<int>> cows(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        cows[x].pb(y);
    }
    for (auto &x : cows) {
        sort(all(x));
    }
    pii cur_ans = {-1, 0};
    vector<int> iter(n, 0), biter(n);
    {
        int cow_cnt = 0;
        int ways = 1;
        for (int i = 0; i < n; ++i) {
            biter[i] = len(cows[i]) - 1;
            while (biter[i] > -1 && cows[i][biter[i]] > tot_cnt[i]) {
                --biter[i];
            }
            if (biter[i] > -1) {
                ++cow_cnt;
                ways *= biter[i] + 1;
                ways %= mod;
            }
        }
        add(cur_ans, mp(cow_cnt, ways));
    }
    vector<int> cur_cnt(n, 0);
    for (auto &x : a) {
        ++cur_cnt[x];
        if (biter[x] > -1 && cows[x][biter[x]] > tot_cnt[x] - cur_cnt[x]) {
            --biter[x];
        }
        if (iter[x] < len(cows[x]) && cows[x][iter[x]] <= cur_cnt[x]) {
            ++iter[x];
        } else {
            continue;
        }
        int cow_cnt = 0, ways = 1;
        for (int i = 0; i < n; ++i) {
            int a = iter[i], b = biter[i] + 1;
            if (i == x) {
                ++cow_cnt;
                if (b >= a) {
                    --b;
                }
                if (b) {
                    ++cow_cnt;
                    ways *= b;
                    ways %= mod;
                }
                continue;
            }
            if (a > b) {
                swap(a, b);
            }
            if (b == 0) {
                continue;
            }
            ++cow_cnt;
            if (b == 1) {
                ways *= a + b;
                if (ways > mod) {
                    ways -= mod;
                }
                continue;
            }
            if (a) {
                ++cow_cnt;
                ways *= a * (b - 1);
                ways %= mod;
            } else {
                ways *= b;
                ways %= mod;
            }
        }
        add(cur_ans, mp(cow_cnt, ways));
    }
    cout << cur_ans.first << " " << cur_ans.second % mod << endl;
}