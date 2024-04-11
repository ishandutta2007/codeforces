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

const int nmax = 300100;

char s[nmax];
int n, k;
int num[nmax];
int pos[nmax];
int res[nmax];
int cnt[nmax];
int len[nmax];

void build(){
    vector<pair<pii, int> > e;
    forn(i, n)
        e.pb(mp(mp((int)s[i], (int)s[i]), i));
    sort(all(e));
    num[e[0].sc] = 0;
    for (int i = 1; i < n; i++){
        if (e[i].fs != e[i-1].fs)
            num[e[i].sc] = num[e[i-1].sc] + 1;
        else
            num[e[i].sc] = num[e[i-1].sc];
    }

    int now = 1;
    while (now < n){
        forn(i, n)
            e[i] = mp(mp(num[i], num[(i + now) % n]), i);
        sort(all(e));
        num[e[0].sc] = 0;
        for (int i = 1; i < n; i++){
            if (e[i].fs != e[i-1].fs)
                num[e[i].sc] = num[e[i-1].sc] + 1;
            else
                num[e[i].sc] = num[e[i-1].sc];
        }
        now *= 2;
    }
    forn(i, n){
        res[num[i]] = i;
        pos[num[i]] = i;
    }   
}

void write(int i, int len){
    forn(j, len)
        printf("%c", s[res[i] + j]);
    puts("");
    exit(0);
}

int main ()
{
    gets(s);
    cin >> k;
    n = strlen(s);
    s[n] = '#';
    n ++;
    build();
    forn(i, n)
        len[i] = n - res[i] - 1;
    {
        int l = 1;
        int r = n - 1;
        int now = 0;
        while (l <= r){
            if (len[l] == now)
                l ++;
            if (l > r)
                break;
            int x = l;
            int sum = 0;
            while (k > 0 && x <= r && s[res[x] + now] == s[res[l] + now]){
                k --;
                sum += len[x] - now - 1;
                x ++;
            }
            if (k == 0)
                write(x-1, now + 1);
            if (k > sum){
                k -= sum;
                l = x;
                continue;
            }else{
                r = x - 1;
                now ++;
                continue;
            }
        }
    }
    puts("No such line.");

    return 0;
}