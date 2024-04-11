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

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int a, b;
string s, t;

bool read() {

    if (!(cin >> a >> b))
        return false;
    cin >> s >> t;
    
    return true;
}

const int N = 200;
int pos[N];
li lt[N];

void solve() {

    forn (i, N)
        pos[i] = -1;

    pos[0] = 0;
    
    int ft = 0;
    li cnt = 0;
    forn (i, a) {
        forn (j, s.size())
            if (t[ft] == s[j])
                ft = (ft + 1) % t.size(), cnt++;
        if (pos[ft] != -1) {
            int d = i + 1 - pos[ft];
            int add = cnt - lt[ft];
            while(i + d < a) {
                i += d;
                cnt += add;
            }
        } else
            pos[ft] = i + 1, lt[ft] = cnt;
    }   

    cout << cnt / (b * t.size()) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}