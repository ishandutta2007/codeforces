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


const int nmax = 1010;

int a[nmax], b[nmax];
int n, k;
bool used[nmax];


int main ()
{

    cin >> n >> k;
    forn(i, n)
        cin >> b[i];
    for (int i = 0; i < n; i++){
        int now = -1;       
        for (int j = 0; j < n; j++)
            if (b[j] == 0 && !used[j]){
                now = j;
                break;
            }
        assert(now >= 0);
        used[now] = 1;
        a[i] = now + 1;
        for (int j = 0; j < n; j++)
            if (!used[j] && j + k <= now)
                b[j] --;
    }

    forn (i, n)
        cout << a[i] << " ";
    cout << endl;   



    return 0;
}