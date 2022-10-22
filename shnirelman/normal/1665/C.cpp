#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

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

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

/*
*/

bool operator < (const pair<pii, int>& a, const pair<pii, int>& b) {
    return ((a.f.f + a.f.s) / (a.f.s + 1 ) > (b.f.f + b.f.s) / (b.f.s + 1));
//    if(a.f.s == 0) {
//        if(b.f.s != 0)
//            return true;
//        else
//            return (a.f.f > b.f.f);
//    } else {
//        if(b.f.s == 0)
//            return false;
//        else
//            return ((a.f.f + a.f.s - 1) / a.f.s > (b.f.f + b.f.s - 1) / b.f.s);
//    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    a[0]++;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

//        p--;

        a[p]++;
    }

    sort(a.rbegin(), a.rend());

    int ans = 0;
    int cnt = 0;
//    set<int> st;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            cnt++;
//            st.insert(a[i]);
//            ans = max(ans, i + a[i]);
        }
    }

    int l = cnt - 1, r = n;
    while(r - l > 1) {
        int m = (l + r) / 2;

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                res++;
                if(a[i] + i > m)
                    res += a[i] + i - m;
            }
        }

        if(res <= m)
            r = m;
        else
            l = m;
    }

    cout << r << endl;

//    set<pair<pii, int>> st;
//    st.emplace(pii(1, 0), -1);
//    for(int i = 0; i < n; i++) {
//        if(a[i])
//            st.emplace(pii(a[i], 0), i);
//    }
//
//    int ans = INF;
//    int cur = 0;
//    while(!st.empty()) {
//        int x = st.begin()->f.f, k = st.begin()->f.s, ind = st.begin()->s;
//        if(k != 0)
//            ans = min(ans, /*cur + */min(int(st.size()), (x + k) / (k + 1)));
//
//        st.erase(st.begin());
//
//        cur++;
//
//        if()
//
//        k++;
//
//
//    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}