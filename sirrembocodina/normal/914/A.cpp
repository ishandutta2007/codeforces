#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[100100];

int main() {
    ios::sync_with_stdio(false);
    int n;
    int a = -1000000000;
    cin >> n;
    forn (i, n) {
        int x;
        cin >> x;
        bool sqr = false;
        for (int i = 0; i * i <= x; ++i) {
            if (i * i == x) {
                sqr = true;
            }
        }
        if (!sqr) {
            a = max(a, x);
        }
    }
    cout << a << endl;
    return 0;
}