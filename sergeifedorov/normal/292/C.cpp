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

vector<vector<int> > res;
int n;
int us[10];

void add(vector<int> a) {
    if (a.size() == 4)
        res.pb(a);
}

void go(const string &s, vector<int> a, int n) {
    if (n == s.size()) {
        add(a);
        return;
    }
    for (int i = 1; i <= 3 && n + i <= s.size(); i ++) {
        int now = 0;
        forn(j, i)
            now = now * 10 + s[n+j] - '0';
        if (s[n] == '0' && i > 1) break;
        if (now > 255) break;
        a.pb(now);
        go(s, a, n + i);
        a.pop_back();
    }
}
void calc(string s) {
//  cerr << s.size() << endl;
    if (s.size() < 4) return;
    int nw[10];
    memset(nw, 0, sizeof nw);
    forn(j, s.size())
        nw[s[j]-'0'] ++;
    forn(j, 10)
        if (us[j] && nw[j] == 0) return;

    vector<int> now;
    go(s, now, 0);
}

void check(string s) {
    if (s.size() < 2) return;
    string w = s;
    reverse(all(w));
    calc(s + w);
    w = w.substr(1, (int)w.size() - 1);
    calc(s + w);
}

void go(string s) {
    check(s);
    if (s.size() == 6) return;
    int n = s.size();
    s += '0';
    forn(i, 10)
        if (us[i]) {
            s[n] = '0' + i;
            go(s);
        }
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n) {
        int x;
        cin >> x;
        us[x] = 1;
    }

    if (n <= 6)
        go("");

    cout << res.size() << endl;
    forn(i, res.size()) {
        forn(j, res[i].size()) {
            printf("%d", res[i][j]);
            if (j < 3) 
                printf(".");
            else
                puts("");
        }
    }

    return 0;
}