#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
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

pair<int, int> a[510];
bool used[510];
int p[510], b[1010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    forn (i, n) {
        scanf("%d", &a[i].fs);
        a[i].sc = i;
    }
    sort(a, a + n);
    int cur = 0;
    forn (i, m) {
        scanf("%d", &b[i]);
        --b[i];
        forn (j, n) {
            if (a[j].sc == b[i]) {
                b[i] = j;
                break;
            }
        }
        if (!used[b[i]]) {
            used[b[i]] = true;
            p[cur++] = b[i];
        }
    }
    long long ans = 0;
    forn (i, m) {
        int k = 0;
        forn (j, n) {
            if (p[j] == b[i]) {
                k = j;
                break;
            }
            ans += a[p[j]].fs;
        }
        ford (j, k) {
            p[j + 1] = p[j];
        }
        p[0] = b[i];
    }
    cout << ans << endl;
    return 0;
}