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

const int nmax = 5 * 1000 * 1000;
const int alph = 26;

map<char, int> next[nmax];
int cnt[nmax];
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
        build();
    }

};

bor a[12];
string s;
bor st;
int n;
int res = 0;

void go (int pos, const vector<int> &now) {
    int buf = 1;
    forn(i, now.size()) {
        int q = 0;
        if (now[i] != -1) q = cnt[now[i]];
        if (q < a[i].l) return;
        if (q > a[i].r) buf = 0;
    }
    if (pos != st.st && buf) 
        res ++;
    forn(i, 26)
        if (next[pos].count(i) != 0) {
            vector<int> nxt = now;
            forn(j, n)
                if (now[j] != -1) {
                    if (next[now[j]].count(i) == 0)
                        nxt[j] = -1;
                    else
                        nxt[j] = next[now[j]][i];
                }
            go(next[pos][i], nxt);          
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
    res = 0;
    vector<int> now;
    forn(i, n)
        now.pb(a[i].st);
    go(st.st, now);
    cout << res << endl;

    return 0;
}