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

const int nmax = 100100;

int n, m;
int a[nmax];
int used[nmax];
int tip[nmax];
int in[nmax], out[nmax];
char buf[100];
int res[nmax];


int main ()
{
    int n;
    cin >> n >> m;
    gets(buf);
    int w = 0;
    forn(i, n){
        gets(buf);
        char ch = buf[0];
        sscanf(buf + 1, "%d", &a[i]);
        a[i] --;
        if (ch == '+')in[a[i]] ++, tip[i] = 1;
        if (ch == '-') out[a[i]] ++, tip[i] = 2, w ++;

    }
    int cnt = 0;
    forn(i, n)
        if (in[i] + w - out[i] == m){
            used[i] = 1;
            cnt++;
        }
    forn(i, n){
        if (tip[i] == 1){
            if (used[a[i]]){
                if (cnt > 1)
                    res[i] = -1;
                else
                    res[i] = 1;
            } else res[i] = 0;
        } else {
            if (used[a[i]]){
                if (cnt > 1)
                    res[i] = -1;
                else
                    res[i] = 0;
            } else res[i] = 1;
        }
    }
    forn(i, n){
        if (res[i] == 1)
            puts("Truth");
        if (res[i] == 0)
            puts("Lie");
        if (res[i] < 0)
            puts("Not defined");
    }


    return 0;
}