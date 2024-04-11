//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 150005;
vector<pi> tot;
void push(int a, int b) {
    tot.pb(mp(a, b));
}
void push(int a, int b, int c) {
    push(a << c, b << c);
}

int cnt[20];
int gid(int c) {
    for (int i = 0; i < 20; i++)
        if ((1 << i) == c) return i;
    return -1;
}
vi cal(int n, int w) { // w : number of moves
    // return result
    //cout << "CAL" << n << ' ' << w << endl;
    if (n <= 2) {
        vi res;
        for (int i = 1; i <= n; i++)
            res.pb(i << w);
        return res;
    }

    int nx = 0;
    for (int j = 0; j < 20; j++) {
        if ((1 << j) >= n) {
            nx = (1 << j);
            break;
        }
    }
    if (nx == n) {
        vi gg = cal(n - 1, w);
        gg.pb(n << w);
        return gg;
    }

    vi cc;
    int mx = (n - nx / 2), ts = nx - n; // >= ts: used
    for (int i = n; i > nx / 2; i--) {
        push(i, nx - i, w);
        cc.pb(nx << w);
    }
    vi cr = cal(mx, w + 1);
    vi gg = cal(ts - 1, w);
    cc.pb(nx / 2 * (1 << w));
    //cout << cc.size() << ' ' << cr.size() << ' ' << gg.size() << endl;
    for (auto v : cr) cc.pb(v);
    for (auto v : gg) cc.pb(v);
    memset(cnt, 0, sizeof(cnt));
    int cnt0 = 0;
    for (auto g : cc) {
        if (g == 0) cnt0 += 1;
        else cnt[gid(g)] += 1;
    }
    int to = gid(nx) + w;
    if (!cnt0)
        for (int j = 0; j < to; j++) {
            if (cnt[j] >= 2) {
                cnt0 += 1;
                push(1 << j, 1 << j);
                cnt[j + 1] += 1;
                cnt[j] -= 2;
                break;
            }
        }
    assert(cnt0);
    for (int j = 0; j < to; j++) {
        for (int k = 0; k < cnt[j]; k++) {
            push(1 << j, 0);
            push(1 << j, 1 << j);
        }
        cnt[j + 1] += cnt[j], cnt[j] = 0;
    }
    vi res;
    for (int i = 0; i < cnt0; i++) res.pb(0);
    for (int i = 0; i < cnt[to]; i++) res.pb(1 << to);
    assert(res.size() == n);
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) cout << "-1" << endl;
        else {
            tot.clear();
            vi cur = cal(n, 0);
            sort(cur.begin(), cur.end());
            for (int i = 0; i < cur.size(); i++)
                if (!cur[i]) 
                    push(0, cur[cur.size() - 1]);
            printf("%d\n", tot.size());
            for (auto v : tot) printf("%d %d\n", v.fi, v.se);
        }
    }
    return (0-0); //<3
}