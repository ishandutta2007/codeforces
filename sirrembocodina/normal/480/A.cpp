#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

pair<int, int> a[5010];

int main() {
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i].fs >> a[i].sc;
    }
    sort(a, a + n);
    int ans = 0;
    forn (i, n) {
        if (ans <= a[i].sc) {
            ans = a[i].sc;
        } else {
            ans = a[i].fs;
        }
    }
    cout << ans;
}