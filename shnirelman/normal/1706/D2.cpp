#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 1e5 + 13;
const int LOGN = 30;

int M;

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

mt19937 rnd(45567);

int a[N], b[N];
int x[N], y[N];
//int dv[N];
//queue<int> q[N];
vector<int> q[N];
int cnt[N];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < N; i++) {
        b[i] = x[i] = /*y[i] = */cnt[i] = 0;
        q[i].erase(q[i].begin(), q[i].end());
//        while(!q[i].empty())
//            q[i].pop();
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    multiset<int> st;
//    map<int, int> mp;
    int mx = N - 1, mn = INF;
    for(int i = 0; i < n; i++) {
//        dv[i] = a[i] + 1;
        b[i] = a[i];
        x[i] = 2;
//        while(x[i] < k && a[i] / x[i] == a[i])
//            x++;
//        y[i] = INF;

        cnt[b[i]]++;
        mn = min(mn, b[i]);

        y[i] = int(sqrt(a[i]));
        if((y[i] + 1) * 1ll * (y[i] + 1) == a[i])
            y[i]++;

//        st.insert(b[i]);
    }


    while(mx > 0 && cnt[mx] == 0)
        mx--;

//    int ans = *st.rbegin() - *st.begin();
    int ans = mx - mn;

    if(k == 1) {
        cout << ans << endl;
        return;
    }

//    set<pii> ord;
    for(int i = 0; i < n; i++) {
//        ord.emplace(-(a[i] / (x[i] + 1)), i);
//        q[b[i] / (x[i])].push_back(i);

        q[b[i]].push_back(i);
    }

    for(int cur = N - 1; cur >= 0; cur--) {
//    for(int cur = 15; cur >= 0; cur--) {
        for(int i : q[cur]) {
//            int i = q[cur].back();
            cnt[b[i]]--;
            b[i] = cur;
            mn = min(mn, b[i]);
            cnt[b[i]]++;

//            q[cur].pop_back();

//            cout << "iiiiiiiiiiiiiiiiiiii " << i << ' ' << b[i] << endl;

            if(x[i] * x[i] > a[i] || x[i] > k) {
                int nxt = min(cur - 1, y[i]);
                if(/*(cur - 1) * 1ll * (cur - 1) <= a[i] && */a[i] / k <= nxt) {
                    q[nxt].push_back(i);
                }
            } else {
                int nxt = a[i] / (x[i]);
                q[nxt].push_back(i);
//                cout << "push " << i << ' ' << a[i] << ' ' << x[i] << ' ' << a[i] / x[i] << endl;
                while(x[i] <= k && a[i] / (x[i]) >= nxt)
                    x[i]++;
//                while(x[i] < k && a[i] / (x[i] + 1) >= cur)
//                    x[i]++;
//                if(x[i] + 1 < k) {
//                    assert(a[i] / (x[i] + 1) < cur);
//                    q[a[i] / (x[i] + 1)].push_back(i);
//                }

//                if(x[i] * x[i] > a[i]) {
//                    if(a[i] / k <= cur - 1) {
//                        q[cur - 1].push_back(i);
//                    }
//                }

//                cout << "push " << i << ' ' << a[i] / x[i] << ' ' << x[i] << endl;

            }
        }
        vector<int> tmp;
        tmp.swap(q[cur]);
//        q[cur].erase(q[cur].begin(), q[cur].end());

        while(mx > 0 && cnt[mx] == 0)
            mx--;

//        if(cur < 15) {
//            cout << cur  << " -------------- " << mn << ' ' << mx << endl;
//            for(int i = 0; i < n; i++)
//                cout << b[i] << ' ';
//            cout << endl;
//            for(int i = 0; i < n; i++)
//                cout << x[i] << ' ';
//            cout << endl;
////            for(int i = 0; i < n; i++)
////                cout << y[i] << ' ';
////            cout << endl;
//        }





        ans = min(ans, mx - mn);
    }

//    while(!ord.empty()) {
//
//        int i = ord.begin()->s;
//        st.erase(st.find(b[i]));
//        b[i] = -ord.begin()->f;
//        st.insert(b[i]);
//        ord.erase(ord.begin());
//
////        cout << ans << endl;
////        for(int i = 0; i < n; i++)
////            cout << b[i] << ' ';
////        cout << endl;
//
////        cout << i << ' ' << a[i] << ' ' <<
//
//        if(x[i] * x[i] > a[i]) {
//            y[i] = min(y[i], x[i]);
//            if(a[i] / k <= y[i]) {
//                ord.emplace(-y[i], i);
//                y[i]--;
//            }
//
//
//        } else {
//            ord.emplace(-(a[i] / x[i]), i);
//            x[i]++;
//        }
//
//
//        ans = min(*st.rbegin() - *st.begin(), ans);
//    }

    cout << ans << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}