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
int a[310][310];
int b[310];

int main ()
{
    int n;
    cin >> n;
    forn(i, n)
        forn(j, n)
            cin >> a[i][j];
    forn(i, n)
        cin >> b[i];
    forn(i, n){
        int res = 1e9;
        int pos = -1;
        forn(j, n){
            int now = -1;
            forn(k, n)
                if (b[k] <= j + 1 && b[k] != i + 1){
                    now = b[k];
                    break;
                }
            forn(k, n)
                if (now == a[i][k]){
                    if (res > k){
                        res = k;
                        pos = j;
                    }
                }
//          cerr << res << " ";
        }
//      cerr << endl;
        cout << pos + 1 << " ";
    }
    cout << endl;


    return 0;
}