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

const int nmax = 100100;

int n;
vector<int> e;
int sum;
int used[nmax];
int nim[50];
map<int, int> dp;


int calc(vector<int> a) {
    int msk = 0;
    while (a.size() > 0 && a.back() == 0) a.pop_back();
    ford(i, a.size())
        msk = msk * 2 + a[i];
    if (a.size() == 0) return dp[msk] = 0;
    if (dp.count(msk) != 0) return dp[msk];
    set<int> now;
    forn(i, a.size()) {
        vector<int> b = a;
        if (a[i]) {
            for (int j = i; j < b.size(); j += i + 1)
                b[j] = 0;
            int q = calc(b);
            now.insert(q);
        }       
    }

    int res = 0;
    while (now.count(res)) res ++;
    return dp[msk] = res;
}

void pre_calc() {
     string q = "0 1 2 1 4 3 2 1 5 6 2 1 8 7 5 9 8 7 3 4 7 4 2 1 10 9 3 6 11 12 14";
     stringstream st;
     st << q;
    for (int i = 0; i <= 30; i ++) 
        st >> nim[i];
    return;


    
    for (int i = 0; i <= 30; i ++) {
        vector<int> now;
        forn(j, i)
            now.pb(1);
        nim[i] = calc(now);
        cout << nim[i] << " ";
    }   
    cerr << dp.size() << endl;
    cout <<endl;
//  exit(0);
}

void add(int p) {
    int len = 1;
    int64 now = p;
    while (now <= n) {
        len ++;
        now = now * p;
    }
    e.pb(len);
    sum += len;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    pre_calc();
    cin >> n;
    int res = 0;
    for (int i = 2; i * i <= n; i ++) {
        if (used[i]) continue;
        int now = 1;
        for (int64 j = i * i; j <= n; j = j * i) {
            now ++;
            if (j * j <= n)
                used[j] = 1;
        }
        sum += now;
        res = res ^ nim[now];
    }   
    res ^= (n - sum) % 2;
    if (res)
        puts("Vasya");
    else
        puts("Petya");

    return 0;
}