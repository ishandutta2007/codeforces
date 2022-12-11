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

int p1,p2,p3,t1,t2,n,res;
int l[1000],r[10000];

int calc2(int n){
    int dt = min(n,t2);
    return dt*p2 + (n-dt)*p3;
}

int calc(int n){
    int dt = min(n,t1);
    return dt * p1 + calc2(n - dt);
}

int main(){

    cin >>n>> p1 >> p2 >> p3 >> t1 >> t2;
    forn(i,n)
        cin >> l[i] >> r[i];
    res = (r[0] - l[0])*p1;
    for (int i = 1; i < n; i++)
        res += calc(l[i] - r[i-1]) + (r[i] - l[i])*p1;
    cout << res << endl;    


    return 0;
}