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


int n, p;
int a[60];
ldb t[110][110];
ldb dp[110];

void calc(vector<int> a) {
    sort(all(a));
    int n = a.size();
    memset(t, 0, sizeof t);
    t[0][0] = 1;
    forn(i, n) {
        ford(k, n)
            forn(j, p + 1)
                t[j + a[i]][k+1] += t[j][k];
    }
    for (int i = 0; i <= p; i ++) {
        dp[i] = 0;
        for (int j = 0; j <= n; j ++)
            if (t[i][j] > 0) {
                ldb now = j * t[i][j];
                for (int w = j + 1; w <= n; w ++)
                    now = (now * (w - j)) / w;
                dp[i] += now;
            }
    }
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    int sum = 0;
    forn(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> p;
    if (sum <= p) {
        cout << n << endl;
        exit(0);
    }
    ldb res = 0;
    forn(i, n) {
        vector<int> now;
        forn(j, n)
            if (i != j)
                now.pb(a[j]);
        calc(now);
        for (int k = p; k + a[i] > p && k >= 0; k --)
            res += dp[k];
    }
    printf("%0.9lf\n", (double)res / n);
    

    return 0;
}