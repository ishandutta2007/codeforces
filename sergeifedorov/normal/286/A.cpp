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

vector<int> mul(vector<int> a, vector<int> b) {
    vector<int> res;
    forn(i, a.size())
        res.pb(b[a[i]]);
    return res;
}

vector<int> solve(int n) {
    vector<int> a, res;
    forn(i, n) {
        a.pb(i);
        res.pb(n - i - 1);
    }
    while (1) {
        if (mul(a, a) == res) return a;
        if (!next_permutation(all(a))) break;
    }
    return vector<int>();
}

vector<int> gen(int n) {
    int now = 1;
    vector<int> res, b;
    forn(i, n / 4) {
        res.pb(now);
        res.pb(n - now);
        b.pb(n - now - 1);
        b.pb(now - 1);
        now += 2;
    }
    ford(i, b.size())
        res.pb(b[i]);
    return res;
}

void no() {
    puts("-1");
    exit(0);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

/*  forn(i, 10) {
        cerr << i << ": " << endl;
        vector<int> a= solve(i);
        forn(i, a.size())
            cerr << a[i] << " ";
        cerr << endl;
    }*/

    int n;
    cin >> n;
    if (n % 4 == 2 || n % 4 == 3) no();
    vector<int> res;
    int m = n;
    if (m % 4 == 1) m --;
    res = gen(m);
    if (n % 4 == 1) {
        vector<int> a;
        forn(i, res.size() / 2) {
            if (res[i] >= n / 2)
                a.pb(res[i] + 1);
            else
                a.pb(res[i]);
        }
        a.pb(n / 2);
        for (int i = res.size() / 2; i < res.size() ; i++) {
            if (res[i] >= n / 2)
                a.pb(res[i] + 1);
            else
                a.pb(res[i]);
        }
        res = a;
    }   
    forn(i, res.size())
        printf("%d ", res[i] + 1);


    return 0;
}