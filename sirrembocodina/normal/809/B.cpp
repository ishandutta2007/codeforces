#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

const int mod = 1000000007;

void b_search(int &l, int &r) {
    while (l < r) {
        int m = (l + r) / 2;
        cout << "1 " << m << " " << m + 1 << endl;
        cout.flush();
        char tmp[5];
        cin >> tmp;
        if (tmp[0] == 'N') {
            l = m + 1;
        } else {
            r = m;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    b_search(l, r);
    int f_p = l;
//    cerr << "first point: " << f_p << endl;
    l = f_p + 1;
    r = n;
    if (l <= r) {
        b_search(l, r);
        cout << "1 " << l << " " << f_p << endl;
        cout.flush();
        char tmp[5];
        cin >> tmp;
        if (tmp[0] == 'T') {
            cout << "2 " << l << " " << f_p << endl;
            cout.flush();
            return 0;
        }
    }
    l = 1;
    r = f_p - 1;
    b_search(l, r);
    cout << "2 " << l << " " << f_p << endl;
    cout.flush();
    return 0;
}