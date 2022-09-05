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
#include <time.h>

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
const int MAX = 1300000;

int a[3005];

int b[3005];

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    FOR(i,0,n){
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    FOR(i,0,n){
        int a1 = 0;
        int a2 = 0;
        FOR(j,0,i)
            if (a[i] > a[j])
                ++a1;
        FOR(j,i + 1 , n)
            if (a[i] > a[j])
                ++a2;
        if (a2 > a1)
            b[i] = -a[i];
        else b[i] = a[i];
    }
    int res = 0;
    FOR(i,0,n)
        FOR(j,i + 1 , n)
            if (b[i] > b[j])
                ++res;

    cout << res << endl;
    return 0;
}