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
#include <sstream>

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
const int inf = (int)1e9 + 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
int a[100100];


int main ()
{
    int n;
    cin >> n;
    forn(i, n)
        cin >> a[i];
    sort(a, a + n);
    int now = 0;
    int cnt = 0;
    int res = 0;
    forn(i, n){
        if (now + a[i] > 710)
            continue;
        cnt ++;
        now += a[i];
        res += max(0, now - 350);
    }
    cout << cnt << " " << res << endl;



    return 0;
}