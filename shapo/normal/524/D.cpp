#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <omp.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector <ll> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

struct Event {
    int x, type, num; 
    Event(int _t, int _type, int _num) : x(_t), type(_type), num(_num) {} 
}; 

bool cmp(const Event & a, const Event & b) {
    return a.x < b.x || (a.x == b.x && a.type < b.type); 
}

vector<Event> evs;
int n, m, t; 
int col[1000000]; 
int cols[1000000]; 

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    cin >> n >> m >> t; 

    for (int i = 0; i < n; i++) {
        int h, m, s; 
        char c; 
        cin >> h >> c >> m >> c >> s; 
        s += m * 60; 
        s += h * 60 * 60; 

        evs.pb(Event(s, 1, i)); 
        evs.pb(Event(s + t, -1, i)); 
    }

    sort(evs.begin(), evs.end(), cmp); 

    int maxcol = 0; 
    int r = 0; 
    int curcol = 0; 

    for (int i = 0; i < evs.size(); i++) {
        const Event & ev = evs[i]; 
        if (ev.type == 1) {
            if (curcol < m) {
                col[ev.num] = ++r; 
                cols[r]++; 
                curcol++; 
            } else {
                col[ev.num] = r;
                cols[r]++; 
            }
        } else {
            int c = col[ev.num]; 
            cols[c]--; 
            if (cols[c] == 0) {
                curcol--; 
            }
        }
        maxcol = max(maxcol, curcol); 
    }

    if (maxcol != m) {
        cout << "No solution\n"; 
        return 0; 
    }

    cout << r << "\n"; 
    for (int i = 0; i < n; i++) {
        cout << col[i] << "\n"; 
    }

    return 0;
}