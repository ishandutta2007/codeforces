#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const string task = "a";
const string inp = task + ".in";
const string outp = task + ".out";

char a[10][10], b[10][10];
int res;

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(outp.data(),"wt", stdout);
        res = 1e9;
    int n = 8;
    forn(i,n)
        forn(j,n)
            cin >> a[i][j];
    forn(tst,1 << (2*n)){
        int now = 0;
        forn(i,n)
            forn(j,n)
                b[i][j] = 'W';
        forn(j,n*2)
            if (tst & (1 << j)){
                now ++;
                if (j < n)
                    forn(x,n)
                        b[x][j] = 'B';
                else
                    forn(x,n)
                        b[j-n][x] = 'B';
            }
        bool done = 1;
            forn(x,n)
                forn(y,n)
                    if (a[x][y] != b[x][y])
                        done = 0;
        if (done)
            res = min(res,now);
    }
    cout << res << endl;


    return 0;
}