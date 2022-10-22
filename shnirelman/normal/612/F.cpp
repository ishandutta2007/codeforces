//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int n;

int len(int i, int j) {
    return (i <= j ? j - i : n - i + j);
}

int dist(int i, int j) {
    return min(abs(i - j), n - abs(i - j));
}

pair<char, int> get_dist(int i, int j) {
    if(i <= j) {
        if(j - i <= n - j + i)
            return {'+', j - i};
        else
            return {'-', n - j + i};
    } else {
        if(i - j <= n - i + j)
            return {'-', i - j};
        else
            return {'+', n - i + j};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> n >> s;

    s--;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

//    for(auto x : b)
//        cout << x << ' ';
//    cout << endl;

    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ' << *lower_bound(b.begin(), b.end(), a[i]) << ' ' << int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) << endl;
        a[i] = (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
//        cout << a[i] << endl;
    }

//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;

    vector<vector<int>> wh(b.size());
    for(int i = 0; i < n; i++) {
        wh[a[i]].push_back(i);
    }

//    for(int i = 0; i < wh.size(); i++) {
//        cout << i << ": ";
//        for(auto x : wh[i])
//            cout << x << ' ';
//        cout << endl;
//    }

    vector<int> d(n, INF);
    vector<pii> p(n, {-1, -1});

    /*
    set<pair<pii, int>> st;

    {
        if(wh[0].size() == 1) {
            int i = wh[0][0];
            d[i] = min(abs(s - i), n - abs(i - s));
            p[i] = s;
        } else {
            int i = lower_bound(wh[0].begin(), wh[0].end(), s) - wh[0].begin();
            if(i == wh[0].size())
                i = 0;
            int j = (i == 0 ? wh[0].size() - 1 : i - 1);
            if(wh[0][i] == s)
                i = (i == wh[0].size() - 1 ? 0 : i + 1);

            i = wh[0][i];
            j = wh[0][j];

            p[i] = p[j] = s;
            d[i] = len(i, s);//n - abs(s - i);
            d[j] = min(d[j], len(s, j));//n - abs(s - j);

            st.insert({{a[i], d[i]}, i});
            st.insert({{a[j], d[j]}, j});
        }

    }
    */


    vector<pii> lst(1, {s, 0});
    for(int k = 0; k < wh.size(); k++) {
        if(wh[k].size() == 1) {
            int v = wh[k][0];
            for(auto pr : lst) {
                int dp = pr.s;
                int x = pr.f;

                int d1 = dp + dist(x, v);//min(abs(x - v), n - abs(v - x));
//                cout << "single " << v << ' ' << x << ' ' << d1 << endl;
                if(d[v] > d1) {
                    d[v] = d1;
                    p[v] = {x, -1};
                }
            }

            lst = vector<pii>(1, {v, d[v]});
            continue;
        }

        for(int i = 0; i < wh[k].size(); i++) {
            int v = wh[k][i];
            int u = wh[k][(i + 1) % wh[k].size()];
            int w = wh[k][(i + wh[k].size() - 1) % wh[k].size()];

//            cout << k << ' ' << i << ' ' << v << ' ' << u << ' ' << w << endl;

            for(auto pr : lst) {
                int dp = pr.s;
                int x = pr.f;

                int d1 = dp + dist(x, u) + len(u, v);
                int d2 = dp + dist(x, w) + len(v, w);

//                cout << "d1 d2 " << d1 << ' ' << d2 << ' ' << dp << ' ' << d<< endl;
//                cout << "d1 " << d1 << ' ' << dp << ' ' << dist(x, u) << ' ' << len(u, v) << endl;
//                cout << "d2 " << d2 << ' ' << dp << ' ' << dist(x, w) << ' ' << len(v, w) << endl;

                if(d[v] > d1) {
                    d[v] = d1;
                    p[v] = {x, u};
                }

                if(d[v] > d2) {
                    d[v] = d2;
                    p[v] = {x, w};
                }
            }
        }

        lst.erase(lst.begin(), lst.end());
        lst.resize(wh[k].size());
        for(int i = 0; i < wh[k].size(); i++)
            lst[i] = {wh[k][i], d[wh[k][i]]};
    }

//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//
//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << d[i] << endl;
//    }

    /*
    while(!st.empty()) {
        int v = st.begin()->s;
        cout << "while " << v << ' ' << a[v] << ' ' << b.size() << ' ' << d[v] << endl;
        st.erase(st.begin());

        if(a[v] == b.size() - 1)
            break;

        int nxt = a[v] + 1;

        if(wh[nxt].size() == 1) {
            int i = wh[nxt][0];
            cout << "go -> " << i << endl;
            int d1 = min(abs(v - i), n - abs(v - s));
            if(d[i] > d1) {
                p[i] = s;
                st.erase({{nxt, d[i]}, i});
                d[i] = d1;
                st.insert({{nxt, d[i]}, i});
            }
        } else {
            int i = lower_bound(wh[nxt].begin(), wh[nxt].end(), v) - wh[nxt].begin();
            if(i == wh[nxt].size())
                i = 0;
            int j = (i == 0 ? wh[nxt].size() - 1 : i - 1);
            if(wh[nxt][i] == v)
                i = (i == wh[nxt].size() - 1 ? 0 : i + 1);

cout << "go -> " << i << ' ' << j << endl;
            i = wh[nxt][i];
            j = wh[nxt][j];

            cout << "go -> " << i << ' ' << j << endl;

            if(d[i] > d[v] + len(i, v) + abs(v - i)) {
                p[i] = v;
                st.erase({{a[i], d[i]}, i});
                d[i] = d[v] + len(i, v);//abs(v - i);
                st.insert({{a[i], d[i]}, i});
            }

            if(d[j] > d[v] + len(v, j)abs(v - j)) {
                p[j] = v;
                st.erase({{a[j], d[j]}, j});
                d[j] = d[v] + len(v, j);//abs(v - j);
                st.insert({{a[j], d[j]}, j});
            }
        }
    }

*/


    int mn = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b.size() - 1 && (mn == -1 || d[mn] > d[i])) {
            mn = i;
        }
    }

    vector<pair<char, int>> res;

    int v = mn;
    while(true) {
        int k = a[v];

        int i = lower_bound(wh[k].begin(), wh[k].end(), v) - wh[k].begin();

        int par = p[v].f;
        int u = p[v].s;

//        cout << v << ' ' << k << ' ' << par << ' ' << u << endl;

        if(u == -1) {
            res.push_back(get_dist(par, v));
        } else {
            int m = wh[k].size();
            if(m == 2) {
                res.push_back(get_dist(u, v));
            } else {
                if(wh[k][(i + 1) % m] == u) {
                    for(int j = i; j != (i + 1) % m; j = (j == 0 ? m - 1 : j - 1)) {
                        res.push_back(get_dist(wh[k][(j + m - 1) % m], wh[k][j]));
//                        res.push_back(get_dist(wh[k][j], wh[k][(j + 1) % wh[k].size()));
                    }


                } else {
                    for(int j = i; j != (i + m - 1) % m; j = (j == m - 1 ? 0 : j + 1)) {
                        res.push_back(get_dist(wh[k][(j + 1) % m], wh[k][j]));
                    }
                }
            }


            res.push_back(get_dist(par, u));
        }


        if(a[v] == 0)
            break;

        v = par;

    }

    cout << d[mn] << endl;

    reverse(res.begin(), res.end());

    for(auto p : res)
        cout << p.f << ' ' << p.s << endl;
}