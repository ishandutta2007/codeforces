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

    char s[2001000];
    int p[2001000];


int main ()
{
    gets(s);
    int n = strlen(s);
    p[0] = 0;
    for (int i = 1; i < n; i++){
        p[i] = p[i-1];
        while (p[i] > 0 && s[p[i]] != s[i])
            p[i] = p[p[i] - 1];
        if (s[p[i]] == s[i])
            p[i] ++;
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
        res = max(res, min(p[i], i));
    int now = p[n-1];
    while (now > 0 && res < now){
        now = p[now-1];
    }
    res = now;
    if (res == 0)
        puts("Just a legend");
    else
        forn(i, res)
            printf("%c", s[i]);
    puts("");
        
        
            

    return 0;
}