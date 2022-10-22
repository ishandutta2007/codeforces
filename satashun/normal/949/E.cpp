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

V<int> dfs(V<int> vec) {
    vec.erase(unique(ALL(vec)), vec.end());
    {
        V<int> v;
        for (int &x : vec) if (x != 0) {
            v.pb(x);
        }
        vec = v;
    }
    if (vec.size() == 0) {
        return {};
    }
    if (vec[0] == vec.back()) {
        if (vec[0] == 1) {
            return {1};
        } else if (vec[0] == -1) {
            return {-1};
        }
    }

    bool odd = 0;

    for (int v : vec) {
        if (abs(v) % 2 == 1) {
            odd = 1;
        }
    }
    if (!odd) {
        for (int &v : vec) {
            v /= 2;
        }
        V<int> res = dfs(vec);
        for (int &v : res) {
            v *= 2;
        }
        return res;
    } else {
        V<int> nx = vec;
        for (int &v : nx) {
            if (v % 2 != 0) {
                v = (v - 1) / 2;
            } else {
                v /= 2;
            }
        }
        V<int> resp = dfs(nx);
        for (int &v : resp) {
            v *= 2;
        }
        resp.pb(1);

        nx = vec;

        for (int &v : nx) {
            if (v % 2 != 0) {
                v = (v + 1) / 2;
            } else {
                v /= 2;
            }
        }

        V<int> resn = dfs(nx);
        for (int &v : resn) {
            v *= 2;
        }
        resn.pb(-1);
        if (resp.size() > resn.size()) {
            return resn;
        } else {
            return resp;
        }
    }
}

int main() {
    int n; cin >> n;
    V<int> a(n); rep(i, n) cin >> a[i];
    sort(ALL(a));

    auto res = dfs(a);
    int sz = res.size();
    cout << sz << endl;
    rep(i, sz) cout << res[i] << (i == sz - 1 ? '\n' : ' ');

    return 0;
}