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

int k, n;
char buf[100];
vector<int64> a;

int64 get(string s) {
    s += ".";
    int now = 0;
    int64 res = 0;
    forn(i, s.size()) {
        if (s[i] == '.') {
            res = (res << 8) + now;
            now = 0;
        } else
            now = now * 10 + s[i] - '0';
    }
    return res;
}

void write(int64 x) {
    if (x == -1) {
        cout << x << endl;
        exit(0);
    }
    vector<int> res;
    forn(i, 4) {
        res.pb(x % (1 << 8));
        x >>= 8;
    }
    ford(i, res.size()) {
        cout << res[i];
        if (i > 0)
            cout << ".";
        else
            cout << endl;
    }
    exit(0);
}

bool ls(int64 a, int64 b) {
    int64 c = a ^ b;
    while ((c & (c - 1)) != 0) c = c & (c - 1);
    if (a & c) return 1;
    return 0;   
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> k;
    gets(buf);
    forn(i, n) {
        gets(buf);
        string s = buf;
        int64 now = get(s);
        a.pb(now);
    }
    sort(all(a), ls);
//  sort(all(a));
//  forn(i, a.size())
//      cerr << a[i] << " ";
//  cerr << endl;
    int64 res = 0;
    ford(i, 32) {
        res += 1ll << i;
        int now = 1;
//      forn(i, a.size())
//          cerr << (a[i] & res) << " ";
//      cerr << endl;
        forn(j, n-1)
            if ((a[j] & res) != (a[j+1] & res))
                now ++;
        if (now == k)
            write(res);
        if (now > k)
            write(-1);
    }
    write(-1);

    return 0;
}