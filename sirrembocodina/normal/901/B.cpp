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

typedef long long ll;

const int mod = 1000000007;

int a[200];
int b[200];
int c[200];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a[1] = 1;
    b[0] = 1;
    --n;
    forn (i, n) {
        forn (j, 200) {
            c[j] = 0;
        }
        forn (j, i + 2) {
            c[j + 1] = a[j];
        }
        bool was = false;
        forn (j, i + 1) {
            c[j] += b[j];
            if (abs(c[j]) == 2) {
                was = true;
            }
        }
        if (was) {
            was = false;
            forn (j, i + 1) {
                c[j] -= b[j] * 2;
                if (abs(c[j]) == 2) {
                    was = true;
                    cerr << "ASDDF\n";
                }
            }
            if (was) {
                forn (j, i + 2) {
                    c[j] += a[j];
                }
            }
        }
        forn (j, 200) {
            b[j] = a[j];
        }
        forn (j, 200) {
            a[j] = c[j];
        }
    }
    cout << n + 1 << endl;
    forn (i, n + 2) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << n << endl;
    forn (i, n + 1) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}