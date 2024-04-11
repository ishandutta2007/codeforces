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
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 17;

int n, m;
long long y;
long long t[1 << nmax];
int mask[nmax];
int pos[nmax];
bool used[nmax];
int res[nmax];

void no(){
    puts("The times have changed");
    exit(0);
}

long long calc(int m){
    if (t[m] != -1)
        return t[m];
    if (m == ((1 << n) - 1))
        return t[m] = 1;
    int cnt = 0;
    forn(i, n)
        if (m & (1 << i))
            cnt ++;
    t[m] = 0;
    if (!used[cnt]){
        for (int i = 0; i < n; i++)
            if ((!(m & (1 << i))) && ((mask[i] | m) == m))
                t[m] += calc(m | (1 << i));
    }else{
        if ((!(m & (1 << pos[cnt]))) && ((mask[pos[cnt]] | m) == m))
            t[m] += calc(m | (1 << pos[cnt]));
    }
    return t[m];
}

int main ()
{
    cin >> n >> y >> m;

    forn(i, m){
        int a, b;
        cin >> a >> b;
        a --; b--;
        mask[b] |= (1 << a);
    }
    long long now = y - 2001;
/*  memset(t, 255, sizeof t);
    forn(i, n-1){
        pos[i] = i;
        used[i] = 1;
    }
    cerr << calc(0) << endl;
*/
    for (int i = 0; i < n; i++){
        bool done = 0;
        for (int j = 0; j < n; j++)
            if (!used[j]){
                used[j] = 1;
                pos[j] = i;
                res[i] = j + 1;
                memset(t, 255, sizeof t);
                long long cur = calc(0);
                used[j] = 0;
                if (now >= cur){
                    now -= cur;
                    continue;
                }else{
                    done = 1;
                    used[j] = 1;
                    break;
                }
            }
        if (!done)
            no();
    }
    forn(i, n)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}