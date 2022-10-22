//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 4e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

bool unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return false;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];

    return true;
}

pii e[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        e[i] = {v, u};
    }

    int s, t, ds, dt;

    cin >> s >> t >> ds >> dt;

    s--;
    t--;

    vector<pii> res;
    for(int i = 0; i < m; i++) {
        if(e[i].f != s && e[i].f != t && e[i].s != s && e[i].s != t) {
            if(unite(e[i].f, e[i].s)) {
                res.emplace_back(e[i].f, e[i].s);
            }
        }
    }

//    cout << s << ' ' << t << endl;

    set<int> sts, stt, both;
    bool ed_st = false;
    for(int i = 0; i < m; i++) {
        if(e[i].s == t)
            swap(e[i].f, e[i].s);
        if(e[i].s == s)
            swap(e[i].f, e[i].s);

//        cout << e[i].f << ' ' << e[i].s << endl;

        if(e[i].f == s) {
            if(e[i].s == t) {
                ed_st = true;
            } else {
//                cout << "add to sts " << e[i].s << endl;
                sts.insert(getp(e[i].s));
            }
        } /*else if(e[i].f == t) {
            int x = getp(e[i].f);
            if(sts.count(x))
                both.insert(x);
            else
                stt.insert(x);
        }*/
    }

    for(int i = 0; i < m; i++) {
        /*if(e[i].s == t)
            swap(e[i].f, e[i].s);
        if(e[i].s == s)
            swap(e[i].f, e[i].s);

        cout << e[i].f << ' ' << e[i].s << endl;

        if(e[i].f == s) {
            if(e[i].s == t) {
                ed_st = true;
            } else {
                cout << "add to sts " << e[i].s << endl;
                sts.insert(getp(e[i].s));
            }
        } else */if(e[i].f == t) {
            int x = getp(e[i].s);
            if(sts.count(x))
                both.insert(x);
            else {
//                cout << "add to stt " << x << endl;
                stt.insert(x);
            }

        }
    }

    for(auto x : both)
        sts.erase(x);

//    for(auto x : sts)
//        cout << x << ' ';
//    cout << endl;
//    for(auto x : stt)
//        cout << x << ' ';
//    cout << endl;
//    for(auto x : both)
//        cout << x << ' ';
//    cout << endl;

    if(sts.size() >= ds || stt.size() >= dt || sts.size() + stt.size() + both.size() + 1 > ds + dt) {
        cout << "No" << endl;
        return 0;
    }

    ed_st &= both.empty();

    if(ed_st) {
        res.emplace_back(s, t);
    }

    int one_both = (both.empty() ? -1 : *both.begin());
    bool s_one = ed_st, t_one = ed_st;
    if(!ed_st && !both.empty()) {
        both.erase(both.begin());
    }

//    cout << "one " << one_both << ' ' << s_one << ' ' << t_one << endl;
    for(int i = 0; i < m; i++) {
//        cout << "i " << i << ' ' << e[i].f << ' ' << e[i].s << endl;

        if(e[i].f == s) {
            int x = getp(e[i].s);
            if(sts.count(x)) {
                res.push_back(e[i]);
                sts.erase(x);
                ds--;
            } else if(both.count(x) && ds > sts.size() + 1) {
                res.push_back(e[i]);
                ds--;
                both.erase(x);
            } else if(!ed_st && x == one_both && !s_one) {
                s_one = true;
                res.push_back(e[i]);
            }
        } else if(e[i].f == t) {
            int x = getp(e[i].s);
            if(stt.count(x)) {
                res.push_back(e[i]);
                stt.erase(x);
                dt--;
            } else if(both.count(x) && dt > stt.size() + 1) {
                res.push_back(e[i]);
                dt--;
                both.erase(x);
            } else if(!ed_st && x == one_both && !t_one) {
                t_one = true;
                res.push_back(e[i]);
            }
        }

//        cout << i << endl;
//        cout << "res :" << endl;
//        for(auto p : res)
//            cout << p.f << ' ' << p.s << endl;
    }

    cout << "Yes" << endl;
    for(auto pr : res)
        cout << pr.f + 1 << ' ' << pr.s + 1 << endl;
}