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
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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

set<vector<char> > res;

int n;
void add(vector<char> e){
    swap(e[2], e[3]);
    vector<char> h = e;
    forn(i,4){
        forn(j,3)
            swap(e[j], e[j + 1]);
        h = min(h,e);
    }
    res.insert(h);
}   

int main ()
{
    scanf("%d", &n);
    forn(i, n){
        vector<char> e(4, 0);
        forn(j,4)                   
            scanf(" %c ", &e[j]);
        add(e);
        char c;
        scanf("%c%c", &c,&c);
    }
    cout << res.size() << endl;
    
    
    
    return 0;
}