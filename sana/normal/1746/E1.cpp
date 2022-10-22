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


bool ask(set<int> s) {
    cout << "? " << sz(s);
    for (int x : s) cout << " " << x;
    cout << endl;
    
    string ss;
    cin >> ss;
    return ss == "YES";
}

void guess(int x) {
    cout << "! " << x << endl;
    string s; cin >> s;
    if (s == ":)") exit(0);
}

void solve()
{
    int n;
    cin >> n;
    
    set<int> C, L;
    for (int i = 1; i <= n; i++) C.insert(i);
    
    while (sz(C) + sz(L) > 2) {
        set<int> a;
        
        if (sz(C)==2 && sz(L)==1) a = C;
        else {
        {
            auto it = C.begin();
            for (int i = 0; i < (sz(C)+1)/2; i++) {
                a.insert(*(it++));
            }
        }
        {
            auto it = L.begin();
            for (int i = 0; i < sz(L)/2; i++) {
                a.insert(*(it++));
            }
        }
        }
        
        bool ans = ask(a);
        
        set<int> new_L, new_C;
        
        for (int x : L) {
            bool is_L = (a.count(x) ^ ans);
            if (!is_L) new_C.insert(x);
        }
        
        for (int x : C) {
            bool is_L = (a.count(x) ^ ans);
            if (is_L) new_L.insert(x);
            else new_C.insert(x);
        }
        
        C = move(new_C);
        L = move(new_L);
    }
    
    for (int x : C) guess(x);
    for (int x : L) guess(x);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}