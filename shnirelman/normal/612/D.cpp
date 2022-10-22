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
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, pii> mp;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        mp[x].f++;
        mp[y].s++;
    }

    int cur = 0;
    vector<pii> res;
    for(auto p : mp) {
        int x = p.f;
        int a = p.s.f, b = p.s.s;


        cur += a;
        if(cur >= k && (res.empty() || res.back().s > -INF)) {
            res.emplace_back(x, -INF);
        }

        cur -= b;
        if(cur < k && !res.empty() && res.back().s == -INF) {
            res.back().s = x;
        }
    }

//    sort(a.begin(), a.end());
//
//    int cur = 0;
//    int lst = -INF;
//
//    vector<pii> res;
//    for(int i = 0; i < a.size(); ) {
////        cout << i << ' ' << a[i].f << endl;
//        int j = i;
//        int prev = cur;
//        while(i < n * 2 && a[i].f == a[j].f) {
//            cur += a[i].s;
//            i++;
//        }
//
////        cout << j << ' ' << i << ' ' << a[j].f << ' ' << cur << endl;
//
//        if(prev >= k && cur < k) {
//            res.emplace_back(lst, a[j].f);
//        } else if(prev < k && cur >= k) {
//            lst = a[j].f;
//        }
//
//    }

    cout << res.size() << '\n';
    for(auto p : res)
        cout << p.f << ' ' << p.s << '\n';
}