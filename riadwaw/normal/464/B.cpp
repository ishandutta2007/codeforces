/**
 * BE CAREFUL!! I have define int li
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>
using namespace std;

int timer;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void prec();

li det(vector<vector<li>> vector);

#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    //rprec();
    int t = 1;
    //cin >> t;
    while (t--) {
        ++timer;
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}

struct Point {
    li x, y, z;

    Point() {
        x = y = z = 0;
    }
    Point(li x, li y , li z):x(x), y(y), z(z) {

    }
    li sqrLen() const {
        return x * x + y * y + z * z;
    }

    bool operator == (const Point& b) const {
        return x == b.x && y == b.y && z == b.z;
    }

    bool operator < (const Point& b) const {
        return x < b.x || x == b.x && y < b.y || x == b.x && y == b.y && z < b.z;
    }

    Point operator - (const Point& b) const  {
        return Point(x - b.x, y - b.y, z - b.z);
    }

    Point operator + (const Point& b) const  {
        return Point(x + b.x, y + b.y, z + b.z);
    }
};


bool ort(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z == 0;
}
vector<Point> a, b(8);

vector<Point> n;

void rec(int id) {
    if(id == 8) {
        li least = 1000000000000000000LL;
        n.clear();

        for(int i = 1; i < 8; ++i) {
            if(b[i] == b[0]) {
                return;
            }
        }
        for(int i = 1; i < 8; ++i) {

            Point cur = b[i] - b[0];
            //rcout << cur.x << ' ' << cur.y << ' ' << cur.z << endl;
            if(cur.sqrLen() < least) {
                least = cur.sqrLen();
                n.clear();
                n.push_back(cur);
            }
            else if(cur.sqrLen() == least) {
                n.push_back(cur);
            }
        }
        if(n.size() == 3 && least != 0 && ort(n[0], n[1]) && ort(n[1], n[2]) && ort(n[0], n[2])) {
            int pos = 0;
            vector<Point> have(4);
            vector<Point> need(4);
            for(int i = 1; i < 8; ++i) {
                li len = (b[i] - b[0]).sqrLen();
                if(len != least)
                    have[pos++] = b[i];
            }
            assert(pos == 4);
            need[0] = b[0] + n[0] + n[1];
            need[1] = b[0] + n[0] + n[2];
            need[2] = b[0] + n[1] + n[2];
            need[3] = need[0] + n[2];

            sort(all(have));
            sort(all(need));
            if(have == need) {
                cout << "YES\n";
                for(int i = 0; i < 8; ++i) {
                    cout << b[i].x << ' ' << b[i].y << ' ' << b[i].z << "\n";
                }
                exit(0);
            }
        }
        return;
    }
    b[id] = Point(a[id].x, a[id].y, a[id].z);
    rec(id + 1);
    b[id] = Point(a[id].x, a[id].z, a[id].y);
    rec(id + 1);
    b[id] = Point(a[id].y, a[id].x, a[id].z);
    rec(id + 1);
    b[id] = Point(a[id].y, a[id].z, a[id].x);
    rec(id + 1);
    b[id] = Point(a[id].z, a[id].x, a[id].y);
    rec(id + 1);
    b[id] = Point(a[id].z, a[id].y, a[id].x);
    rec(id + 1);
}

void solve() {
    int n = 8;
    a.resize(n);
    for(int i = 0; i < 8; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    b[0] = a[0];

    rec(1);

    cout << "NO";
}