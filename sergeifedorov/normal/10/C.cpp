#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 1e6 + 10;

int n;
long long res;
long long t[200];
long long c[10];
long long f[nmax];

inline int s(int x){
    if (f[x] != 0) return f[x];
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    if (res <= 9)
        return f[x] = res;
    else
        return f[x] = s(res);   
}

int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(oup.data(),"wt", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        t[s(i)]++;
    res = 0;
    memset(c,0,sizeof c);
    int b = n+1;
    for (int a = 1; a <= n; a++){
        int sa = s(a);
        while (1ll*a*(b-1) > n){
            b--;
            c[s(b)]++;
        }
        forn(j,10){
            res += c[j]*t[s(sa*j)];
            res += (t[j] - c[j]) *  (t[s(sa*j)] - 1);
        }
    }
            
    cout << res << endl;    

    return 0;
}