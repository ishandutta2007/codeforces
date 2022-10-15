#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;
const int MAXN = 1e5 + 2;
struct kal{
    int b, p;
};
kal cs[MAXN], ds[MAXN];
int mx[MAXN], mx2[MAXN];
int sh;
int tree[MAXN * 4];
int get(int l, int r) { // [l..r)
    int res = 0;
    for (l += sh, r += sh; l < r; l /= 2, r /= 2) {
        if (l & 1) res = max(res, tree[l++]);
        if (r & 1) res = max(res, tree[--r]);
    }
    return res;
}
// int solve(int n, int c) {
//     int ans = 0;
//         sh = n;
        
//         for (int i = 0; i < sh + sh; ++i)
//             tree[i] = 0;

//         for (int i = 0; i < n; ++i) 
//             tree[sh + i] = cs[i].b;
//         for (int i = sh - 1; i > 0; --i) 
//             tree[i] = max(tree[i + i], tree[i + i + 1]);

//         int ptr = n;
//         for (int i = 0; i < n; ++i) {
//             while (ptr > 0 && (cs[ptr].p + cs[i].p > c || ptr == i)) 
//                 --ptr;
//             dbg(i, ptr, cs[i].p, cs[i].b);
//             if (cs[ptr].p + cs[i].p <= c) {
//                 int pot = max(get(i + 1, ptr + 1), get(0, i));
//                 dbg(pot);
//                 if (pot)
//                     ans = max(pot + cs[i].b, ans);
//             }
//         }
//         return ans;
// }
// int ok(int n, int c) {
//     int ans = 0;
//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)
//             if (cs[i].p + cs[j].p <= c)
//                 ans = max(ans, cs[i].b + cs[j].b);
//     return ans;
// }
int main() {
    // while (1) {
    int nn, c, d;
    cin >> nn >> c >> d;
    // nn = rand() % 5 + 2;
    // c = rand() % 12 + 1;
    dbg(nn, c);
    int n = 0, m = 0;
    for (int i = 0; i < nn; ++i) {
        int b, p;
        char w;
        cin >> b >> p >> w;
        // b = rand() % 5 + 1;
        // p = rand() % 5 + 1;
        // w = 'C';
        dbg(b, p);
        if (w == 'C')
            cs[n++] = {b, p};
        else
            ds[m++] = {b, p};
    }
    cs[n].p = 1e9;
    ds[m].p = 1e9;
    int ans = 0;
    std::sort(cs, cs + n, [](const kal & p1, const kal & p2) {
        return p1.p < p2.p;
    });
    std::sort(ds, ds + m, [](const kal & p1, const kal & p2) {
        return p1.p < p2.p;
    });
    // int x = solve(n, c);
    // int y = ok(n, c);
    // if (x != y) {
    //     dbg(x, y);
    //     break;
    // } else dbg("ok");
    // }
    // c & d
    {
        int cmax = 0;
        for (int i = 0; i < n; ++i) {
            if (cs[i].p > c) break;
            cmax = max(cmax, cs[i].b);
        }

        int dmax = 0;
        for (int i = 0; i < m; ++i) {
            if (ds[i].p > d) break;
            dmax = max(dmax, ds[i].b);
        }

        if (cmax > 0 && dmax > 0)
            ans = cmax + dmax;
    }
    // c & c
    if (n > 1) {
        sh = n;
        
        for (int i = 0; i < sh + sh; ++i)
            tree[i] = 0;

        for (int i = 0; i < n; ++i) 
            tree[sh + i] = cs[i].b;
        for (int i = sh - 1; i > 0; --i) 
            tree[i] = max(tree[i + i], tree[i + i + 1]);

        int ptr = n;
        for (int i = 0; i < n; ++i) {
            while (ptr > 0 && (cs[ptr].p + cs[i].p > c || ptr == i)) 
                --ptr;
            if (cs[ptr].p + cs[i].p <= c) {
                int pot = max(get(i + 1, ptr + 1), get(0, min(i, ptr + 1)));
                if (pot)
                    ans = max(pot + cs[i].b, ans);
            }
        }
    }
    // d & d
    if (m > 1) {
        sh = m;
        
        for (int i = 0; i < sh + sh; ++i)
            tree[i] = 0;

        for (int i = 0; i < m; ++i) 
            tree[sh + i] = ds[i].b;
        for (int i = sh - 1; i > 0; --i) 
            tree[i] = max(tree[i + i], tree[i + i + 1]);

        int ptr = m;
        for (int i = 0; i < m; ++i) {
            while (ptr > 0 && (ds[ptr].p + ds[i].p > d || ptr == i))
                --ptr;
            if (ds[ptr].p + ds[i].p <= d) {
                int pot = max(get(i + 1, ptr + 1), get(0, min(i, ptr + 1)));
                if (pot)
                    ans = max(pot + ds[i].b, ans);
            }
        }
    }

    cout << ans << '\n';


    return 0;
}