#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

int k,n;
int a[100100];
map<int64, int> h;
int us[100100];

int main ()
{
//  freopen("output.txt", "wt", stdout);

    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        exit(0);
    }
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    forn(i, n) {
        h[a[i]] = i + 1;
    }
    int res = 0;
    forn(i, n)
        if (!us[i]) {
            int now = 0;
            int64 w = a[i];
            while(h[w] != 0) {
                now ++;
                us[h[w]-1] = 1;
                w = w * k;
            }
            res += (now + 1) / 2;
        }
    cout << res << endl;

    return 0;
}