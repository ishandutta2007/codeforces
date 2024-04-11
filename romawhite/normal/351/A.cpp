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

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int n;
    cin >> n;
    int s = 0;
    int c = 0;
    FOR(i,0,2 * n){
        double a;
        cin >> a;
        int A = a * 1000 + 0.1;
        A %= 1000;

        if (A != 0){
            ++c;
            s += 1000 - A;
        }
    }

    int res = INF;

    FOR(i,0,n + 1)
        if (i <= c && c <= n + i){
            int t = 1000 * i;
            res = min(res , abs(s - t));
            //cout << i << ' ' << res << ' ' << s <<  endl;
    }

    printf("%d.%03d\n" , res / 1000, res % 1000);

    return 0;
}