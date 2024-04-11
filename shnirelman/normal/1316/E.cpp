#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;
const int P = 7;

/*
*/

int n, k, p;
int a[N];
int b[N][P];

int ord[N];

bool cmp(const int& i, const int& j) {
    return (a[i] > a[j]);
}

bool is[N];

pii c[P][P];

li calc(int i, int x, int cnt, set<int>& used) {
    if(x > cnt)
        return -INF64;
    if(i == p) {
        return (x == cnt ? 0 : -INF64);
    }

    li res = -INF64;
    for(int j = 0; j < p; j++) {
        int ind = c[i][j].s, val = c[i][j].f;
        if(used.count(ind) == 0) {
            used.insert(ind);
            res = max(res, calc(i + 1, x + is[ind], cnt, used) + val);
            used.erase(ind);
        }
    }

    return res;
}

li solve(int cnt) {
    li res = 0;
    for(int i = 0; i < k + cnt; i++) {
        is[ord[i]] = true;
        res += a[ord[i]];
    }

    for(int j = 0; j < p; j++) {
        set<pii> st1, st2;
        for(int i = 0; i < n; i++) {
            int x = b[i][j];
            if(is[i]) {
                st1.insert({b[i][j] - a[i], i});
                if(st1.size() > cnt)
                    st1.erase(st1.begin());
            } else {
                st2.insert({b[i][j], i});
                if(st2.size() > p - cnt)
                    st2.erase(st2.begin());
            }
        }

        for(auto pr : st2)
            st1.insert(pr);

        int cur = 0;
        for(auto pr : st1) {
            c[j][cur++] = pr;
        }
    }

    set<int> used;
    return res + calc(0, 0, cnt, used);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> p >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ord[i] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> b[i][j];
        }
    }

    sort(ord, ord + n, cmp);

//    for(int i = 0; i < n; i++)
//        cout << ord[i] << ' ';
//    cout << endl;

    li ans = 0;

    for(int cnt = 0; cnt <= min(k, p); cnt++) {
        li res = solve(cnt);
        ans = max(ans, res);
//        cout << cnt << ' ' << res << endl;
    }

    cout << ans << endl;
}