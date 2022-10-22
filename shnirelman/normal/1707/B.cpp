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
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

//    set<int> st(a.begin(), a.end());

    int lst = 0;

    while(mp.size() > 1) {
//        vector<int> b(st.begin(), st.end());

//        for(auto p : mp) {
//            cout << p.f << ' ' << p.s << endl;
//        }
//        cout << "--------" << endl;

        map<int, int> mp1;
        for(auto p : mp)
            if(p.s > 1)
                mp1[0] += p.s - 1;

        for(auto it = mp.begin(); next(it) != mp.end(); it++) {
            mp1[next(it)->f - it->f]++;
        }

        mp = mp1;
    }

//    cout << *st.begin() << endl;
    cout << (mp.begin()->s == 1 ? mp.begin()->f : 0) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}