#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull  = unsigned long long;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define int ll

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) {
        x = y;
    }
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) {
        x = y;
    }
}

#define fdiv fdiv228

const int N = 1e6 + 10, LOG = 60;
int n, b, p, m;
char t[N];
int val[N];
int coord[N];
int total_mul = 1;
ll pref[N];

vector<int> mul;
vector<vector<int>> pos;
vector<pair<int, int>> blocks;
vector<int> all_mul_pos;

void build() {
    map<int, vector<int>> pos_mul;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '*') {
            pos_mul[val[i]].push_back(i);
            total_mul *= val[i];
            all_mul_pos.push_back(i);
            if (last <= i - 1) {
                blocks.push_back({last, i - 1});
                sort(val + last, val + i);
            }
            last = i + 1;
        }
    }
    if (last <= n - 1) {
        blocks.push_back({last, n - 1});
        sort(val + last, val + n);
    }
    for (auto i : pos_mul) {
        mul.push_back(i.first);
        pos.push_back(i.second);
    }
    for (int i = 0; i < n; ++i) {
        pref[i] = val[i];
        if (i > 0) {
            pref[i] += pref[i - 1];
        }
    }
}

ll getPref(int l, int r) {
    return pref[r] - (l > 0 ? pref[l - 1] : 0);
}

ll ans = 0;

int cnt[LOG];
bool used[N];

void mark(bool val) {
    for (int i = 0; i < (int)mul.size(); ++i) {
        for (int cur_pos = 0; cur_pos < cnt[i]; ++cur_pos) {
            used[pos[i][cur_pos]] = val;
        }
    }
}

int fdiv[LOG];

void createDiv() {
    int cur_div = 1;
    fill(fdiv, fdiv + (int)blocks.size(), 1);
    int cur_pos = (int)all_mul_pos.size() - 1;
    for (int blockId = (int)blocks.size() - 1; blockId >= 0; --blockId) {
        while (cur_pos >= 0 && all_mul_pos[cur_pos] > blocks[blockId].second) {
            int pos = all_mul_pos[cur_pos];
            cur_div *= val[pos];
            --cur_pos;
        }   
        fdiv[blockId] *= cur_div;
    }
    cur_pos = 0;
    cur_div = 1;
    for (int blockId = 0; blockId < (int)blocks.size(); ++blockId) {
        while (cur_pos < (int)all_mul_pos.size() && all_mul_pos[cur_pos] < blocks[blockId].first) {
            int pos = all_mul_pos[cur_pos];
            if (used[pos]) {
                cur_div *= val[pos];
            }
            ++cur_pos;
        }   
        fdiv[blockId] *= cur_div;
    }
}

int calcCnt(int id, int l, int r, ll need_diff) {
    int L = l - 1, R = r + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        ll cur_diff = (ll)val[M] * (total_mul - fdiv[id]);
        if (cur_diff < need_diff) {
            L = M;
        } else {
            R = M;
        }
    }
    return r - R + 1; 
}

ll calcFans(int id, int l, int r, ll diff, int& need, int it) {
    if (it == 0) {
        int cnt2 = calcCnt(id, l, r, diff + 1);
        need -= cnt2;
        ll sumR = getPref(r - cnt2 + 1, r);
        sumR *= total_mul;
        return sumR;
    } else {
        int cnt = calcCnt(id, l, r, diff);
        int cnt2 = calcCnt(id, l, r, diff + 1);
        if (cnt - cnt2 > need) {
            cnt = need + cnt2;
        }
        need -= cnt - cnt2;
        ll sumL = getPref(l, r - cnt);
        ll sumR = getPref(r - cnt + 1, r - cnt2);
        sumL *= fdiv[id];
        sumR *= total_mul;
        return sumL + sumR;
    }
}

int calcCnt(ll need_diff) {
    int ans = 0;
    int id = 0;
    for (auto [l, r] : blocks) {
        ans += calcCnt(id++, l, r, need_diff);
    }
    return ans;
}

ll calcAns(int cnt_p) {
    ll ans = 0;
    ll L = 0, R = (ll)1e18;
    while (L < R - 1) {
        ll M = (L + R) / 2;
        if (calcCnt(M) >= cnt_p) {
            L = M;
        } else {
            R = M;
        }
    }
    int id = 0;
    int need = cnt_p;
    for (int it = 0; it < 2; ++it) {
        id=  0;
        for (auto [l, r] : blocks) {
            ans += calcFans(id++, l, r, L, need, it);
        }
    }
    ans += total_mul;
    return ans;
}

void relaxAns() {
    int total_cnt = 0;
    for (int i = 0; i < (int)mul.size(); ++i) {
        total_cnt += cnt[i];
    }
    if (total_cnt > b / m) {
        return;
    }
    mark(true);
    createDiv();
    chkmax(ans, calcAns((b - total_cnt * m) / p));
    mark(false);
}

void rec(int top) {
    if (top == (int)mul.size()) {
        relaxAns();
    } else {
        for (int i = 0; i <= (int)pos[top].size(); ++i) {
            cnt[top] = i;
            rec(top + 1);
        }
    }
}

void solve() {
    ans = 1;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '+') {
            ans += val[i];
        } else {
            ans *= val[i];
        }
    }
    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> b >> p >> m;
    int top = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> val[i];
        if (t[i] == '*' && val[i] == 1) {
            continue;
        }
        t[top] = t[i];
        val[top] = val[i]; 
        ++top;
    }
    n = top;
    if (n == 0) {
        cout << "1\n";
        return 0;
    }
    build();
    solve();
    cout << ans << endl;
    return 0;
}