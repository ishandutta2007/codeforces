#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
 
using namespace std;
 
#define next fdfdsfdsfdsfdsfds
#define y1 ggvfdg
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define FILL(a,b) memset((a),b,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
#define y1 asdf
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int MOD = 1000000007;
const double EPS = 1e-7;

int a[100007];
int t[100007];
int n;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    cin >> n;
    FOR(i,0,n)
        cin >> a[i];

    vector<int> d(n + 1);
    
    d[0] = -INF;
    for (int i=1; i<=n; ++i)
        d[i] = INF;
 
    for (int i=0; i<n; i++) {
        int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }


    int res = 0;
    FOR(i,0,n + 1)
        if (d[i] != INF)
            res = max(res , i);
    cout << res << endl;

    return 0;
}