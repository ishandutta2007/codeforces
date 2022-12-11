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

int n;
string s, t;
char buf[10001000];
int a[2][2];

void win1() {
    puts("First");
    exit(0);
}

void win2() {
    puts("Second");
    exit(0);
}

void win0() {
    puts("Draw");
    exit(0);
}

void solve(int a, int b, int c, int d) {
    int q, w;
    q = w = 0;
    while (a > 0 || b > 0 || c > 0 || d > 0) {
        if (d > 0) q ++, d --;
        else if (b > 0) q ++, b --;
        else if (c > 0) c--;
        else a --;

        if (a + b + c + d == 0) break;

        if (d > 0) w ++, d --;
        else if (c > 0) w ++, c --;
        else if (b > 0) b--;
        else a --;
    }
    cerr << q << " " << w << endl;
    if (q > w) win1();
    if (q < w) win2();
    win0();

}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n;
    gets(buf);
    gets(buf);
    s = buf;
    gets(buf);
    t = buf;
    forn(i, 2*n)
        a[s[i]-'0'][t[i]-'0'] ++;
    solve(a[0][0], a[1][0], a[0][1], a[1][1]);
    

    return 0;
}