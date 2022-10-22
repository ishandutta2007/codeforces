//
// Created by  on 2019/11/11.
//

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os<<"{";
    rep(i, v.size()) {
        if (i) os<<",";
        os<<v[i];
    }
    os<<"}";
    return os;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    V<int> pr(n, -1);

    set<int> p0, p1;

    rep(i, n) {
        if (s[i] == '0') {
            if (p1.size()) {
                int la = *p1.begin();
                pr[i] = la;
                p1.erase(la);
            }
            p0.insert(i);
        } else {
            if (p0.size()) {
                int la = *p0.begin();
                pr[i] = la;
                p0.erase(la);
            } else {
                puts("-1");
                return 0;
            }
            p1.insert(i);
        }
    }

    if (p1.size()) {
        puts("-1");
        return 0;
    }

    V<int> use(n, 0);
    VV<int> ans;
    for (int i = n-1; i >= 0; --i) {
        if (use[i]) continue;
        int cur = i;
        V<int> vs;
        while (cur != -1) {
            use[cur] = 1;
            vs.pb(cur);
            cur = pr[cur];
        }
        reverse(ALL(vs));
        ans.pb(vs);
    }

    cout << ans.size() << "\n";
    for (auto &v : ans) {
        int sz = v.size();
        cout << sz;
        for (int i : v) {
            cout << " " << i + 1;
        }
        cout << "\n";
    }

    return 0;
}