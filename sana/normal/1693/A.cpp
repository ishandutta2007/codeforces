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
 
 
using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define all(x) begin(x), end(x)


#define each(a,x) for (auto& a: x)
#define tcT template<class T


template<class T> using V = vector<T>; 


tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n);
    vector<long long> a(n); re(a);
    vector<long long> b(n);
    
    partial_sum(all(a), b.begin());
    bool ok = true;
    
    int z = find(all(b), 0) - b.begin();
    
    for (int i = z; i < n; i++) if (b[i] != 0) ok = false;
    for (int i = 0; i < z; i++) if (b[i] <= 0) ok = false;
    if (z == n) ok = false;
    cout << (ok ? "Yes" : "No") << '\n';
}

void solve()
{
    ints(t);
    for (; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}