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

const int nmax = 100;
const long long MX = (long long)1e18;

long long f[nmax];
long long s[nmax];
int cnt;

void push(long long now){
    f[cnt] = now;
    if (cnt == 0)
        s[0] = now;
    else
        s[cnt] = s[cnt-1] + now;
    cnt ++;
}

void gen(){
    long long n1, n2;
    n1 = 1;
    n2 = 2;
    push(n1);
    push(n2);
    while(1){
        long long now = n1 + n2;
        if (now > MX)
            break;
        push(now);
        n1 = n2;
        n2 = now;
    }
}

long long solve(long long x, int lst){
    if (x < 0 || x > s[lst])
        return 0;
    if (x == 0)
        return 1;
    long long res = 0;
    for (int i = lst; i >= 0; i--)
        res = res + solve(x - f[i], i - 1);
    return res;
}

long long get(long long now){
    for (int i = cnt - 1; i >= 0; i --)
        if (f[i] <= now)
            return f[i];
}

long long cur[nmax];
long long res;
long long x;
long long t[nmax][2];

void update(){
    long long now = 0;
    forn(i, cnt){
        if (cur[i] > 0)
            now += f[i];
        if (cur[i] > 1)
            return;
    }
    if (now == x)   
        res ++;
}

void push(int x){
    cur[x-1] ++;
    cur[x-2] ++;
    cur[x] = 0;
    for (int i = x - 1; i >= 2; i--){
        long long dd = max(cur[i] - 1, 0ll);
        cur[i-2] += dd;
        cur[i-1] += dd;
        cur[i] -= dd;
    }
}


long long solve(){
    
    long long now = x;
    memset(cur, 0, sizeof cur);
    ford(i, cnt){
        if (now >= f[i]){
            cur[i] =1;
            now -= f[i];
        }
    }
    memset(t, 0, sizeof t);
    t[0][0] = t[0][1] = 1;
    for (int i = 1; i < cnt; i++){
        t[i][0] = t[i][1] = t[i-1][cur[i-1]];
        if (cur[i-1] == 1){
            t[i][1] += 0;//t[i-1][1];
        }else{
            int w = i-2;
            while (w > 1 && cur[w] == 1 && cur[w-1] == 0)
                w -= 2;
            if (cur[w] == 0)
                t[i][1] += t[w][1];
        }
    }
    res = t[cnt-1][cur[cnt-1]];

    cout <<res << endl;
    return res;
}

int main ()
{
    gen();  
    int tst;
    cin >> tst;
//  tst = 100000;
    forn(i, tst){
        cin >> x;
//      x =(long long)1e18;
        solve();
    }

//  cerr << clock() << endl;

    return 0;
}