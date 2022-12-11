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

const int nmax = 4 * 1000 * 1000;
const int alph = 26;

map<char, int> next[nmax];
short cnt[nmax];
int sz;

struct bor{
    string s;
    int l, r, st;

    bor () {
    }

    void build() {
        st = sz ++;
        for (int i = 0; i < s.size(); i ++)  {
            int now = st;
            for (int j = i; j < s.size(); j ++) {
//              cerr << i << " " << j << " " << s[j] << " " << now << endl;
                cnt[now] ++;
                char c = s[j] - 'a';
                if (next[now].count(c) == 0) next[now][c] = sz ++;
                now = next[now][c];
            }
            cnt[now] ++;
        }
    }   

    void read() {
        cin >> s >> l >> r;
//        build();
    }

};

bor a[12];
string s;
bor st;
int n;
int res = 0;
short good[nmax/2];

void go (int pos, int now, int id) {
        int q = 0;
            if (now != -1) q = cnt[now];
            if (q < a[id].l) return;
            if (q <= a[id].r) good[pos] ++;
    forn(i, 26)
        if (next[pos].count(i) != 0) {
                int nxt = now;
               if (now != -1) {
                    if (next[now].count(i) == 0)
                        nxt = -1;
                    else
                        nxt = next[now][i];
               }
                go(next[pos][i], nxt, id);          
        }
}

int main ()
{
     memset(cnt, 0, sizeof cnt);
     sz = 1;

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> s;
    cin >> n;
    forn(i, n)
        a[i].read();
    st.s = s;
    st.build();
    forn(i, sz)
            good[i] = 0;
    forn(i, n) {
            int buf = sz;
            a[i].build();
            go(st.st, a[i].st, i);
            for (int j = buf; j < sz; j ++) {
                 next[j].clear();
                cnt[j] = 0;
            }
            sz = buf;
    }

    res = 0;
    forn(i, sz)
        if (good[i] == n && i > 1)
            res ++;
        cout << res << endl;

    return 0;
}