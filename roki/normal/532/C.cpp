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

#define y1 ____y1

int x1, y1, x2, y2;

bool read() {
    if (!(cin >> x1 >> y1 >> x2 >> y2))
        return false;
    return true;
}

int dx[3] = {0, -1, -1};
int dy[3] = {-1, 0, -1};

int dist2(int x, int y) {
    return x + y - min(x, y);
}

int dist(int x, int y) {
    return x + y;
}

void solve() {
    if (dist(x1, y1) <= dist2(x2, y2)) {
        cout << "Polycarp" << endl;
        return;
    }

    int p = 0;
    while(true) {
        if (p == 0) {
            int dif = x2 - x1;
            if (dif < 0) {
                forn (i, 2) {
                    int nx = x1 + dx[i], ny = y1 + dy[i];
                    if (nx < 0 || ny < 0 || nx == x2 && ny == y2)
                        continue;
                    x1 = nx, y1 = ny;
                    break;
                }
            } else {
                int ty = y2 - dif;
                if (ty > y1) {
                    for (int i = 1; i >= 0; --i) {
                        int nx = x1 + dx[i], ny = y1 + dy[i];
                        if (nx < 0 || ny < 0 || nx == x2 && ny == y2)
                            continue;
                        x1 = nx, y1 = ny;
                        break;
                    }   
                } else {
                    forn (i, 2) {
                        int nx = x1 + dx[i], ny = y1 + dy[i];
                        if (nx < 0 || ny < 0 || nx == x2 && ny == y2)
                            continue;
                        x1 = nx, y1 = ny;
                        break;
                    }
            
                }
            }
        } else {
            for (int i = 2; i >= 0; --i) {
                int nx = x2 + dx[i], ny = y2 + dy[i];
                if (nx < 0 || ny < 0 || nx == x1 && ny == y1)
                    continue;
                x2 = nx, y2 = ny;
                break;
            }
        }
        if (x1 == 0 && y1 == 0) {
            cout << "Polycarp" << endl;
            return;
        }
        if (x2 == 0 && y2 == 0) {
            cout << "Vasiliy" << endl;
            return;
        }
        p = 1 - p;
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while(read())
        solve();
    
    return 0;
}