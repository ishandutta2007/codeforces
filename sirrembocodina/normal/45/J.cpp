#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fordab(i, a, b) for(int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define PI 3.1415926535897932
#define INF 1000000000

int n, m;
int a[110][110];

int main() {
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    if (n < 3 && m < 3) {
        cout << -1;
        return 0;
    }
    if (n == 2 && m == 3) {
        cout << "3 6 2" << endl << "5 1 4";
        return 0;
    }
    if (n == 3 && m == 2) {
        cout << "5 3" << endl << "1 6" << endl << "4 2";
        return 0;
    }
    if (n == 1) {
        if (m < 4) {
            cout << -1;
            return 0;
        }
        if (m == 4) {
            cout << "3 1 4 2";
            return 0;
        }
    }
    if (m == 1) {
        if (n < 4) {
            cout << -1;
            return 0;
        }
        if (n == 4) {
            cout << 3 << endl << 1 << endl << 4 << endl << 2;
            return 0;
        }
    }
    int cur = 1;
    forn (i, n) {
        forn (j, m) {
            if ((i + j) % 2) {
                continue;
            }
            a[i][j] = cur++;
        }
    }
    forn (i, n) {
        forn (j, m) {
            if ((i + j) % 2 == 0) {
                continue;
            }
            a[i][j] = cur++;
        }
    }
    forn (i, n) {
        forn (j, m) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}