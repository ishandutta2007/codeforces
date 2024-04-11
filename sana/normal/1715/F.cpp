#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


using namespace std;
 

#define sz(x) (int)(x).size()


#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }

tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


const double eps = 1e-13;

double ask(vector< pair<double, double> > poly) {
    ps("?", sz(poly));
    for (auto [a, b] : poly) {
        cout << a << " " << b << '\n';
    }
    cout.flush();
    
    double res;
    re(res);
    return res;
}

void solve()
{
    int n, m;
    re(n,m);
    cout << fixed << setprecision(15);
    
    vector< pair<double, double> > poly;
    for (int i = 0; i < m; i++) {
        poly.emplace_back(i == 0 ? 0 : eps, i);
        poly.emplace_back(n, i + 0.2);
        poly.emplace_back(i == m-1 ? 0 : eps, i + 0.2);
    }
    
    double res = ask(poly);
    dbg(res);
    double x = n * res / 0.2 - 0.5;
    x = n - x - 1;
    
    poly.clear();
    for (int i = 0; i < n; i++) {
        poly.emplace_back(i, i == 0 ? 0 : eps);
        poly.emplace_back(i + 0.2, m);
        poly.emplace_back(i + 0.2, i == n-1 ? 0 : eps);
    }
    
    res = ask(poly);
    double y = m * res / 0.2 - 0.5;
    y = m - y - 1;
    
    ps("!",x,y);
    cout.flush();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}