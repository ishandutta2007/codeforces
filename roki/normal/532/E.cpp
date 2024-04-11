#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define sqr(x) ((x) * (x))
typedef pair<li, li> pt;
#define ft first
#define sc second
#define x first
#define y second

int n;
string s, t;

bool read() {
    if (!(cin >> n >> s >> t))
        return false;
    return true;
}

string calc() {
    string cur;
    forn (i, n)
        if (s[i] == t[i])
            cur += s[i];
        else
            break;

    int l = cur.size();

    cur += t[l]; // ,    

    while(l < n)
        cur += s[l++]; //   

    bool bad = false;

    forn (i, n)
        if (cur[i + bad] != t[i]) {
            if (bad)
                return "";
            bad = true;
            i--;
        }

    return cur;
}

void solve() {
    
    set<string> ans;

    string res = calc();
    if (res != "")
        ans.insert(res);
    swap(s, t);
    res = calc();
    if (res != "")
        ans.insert(res);
    cout << ans.size() << endl;

}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}