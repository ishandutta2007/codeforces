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
    int n, m;
    cin >> n >> m;
    if (n >= 30) {
        cout << m << endl;
    } else {
        cout << (m & ((1 << n) - 1)) << endl;
    }
    return 0;
}