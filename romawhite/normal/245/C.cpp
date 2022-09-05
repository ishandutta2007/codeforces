//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
#include <sstream>
#include <fstream>

 
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
#define SZ(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const long double pi=acos(-1.0);
const int INF=1000000000;
const int mod = 1000000007;


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR(i,1,n + 1)
        cin >> a[i];
    int res = 0;
    if (n % 2 == 0 || n == 1){
        cout << -1 << endl;
        return 0;
    }
    RFOR(i,n + 1,2){
        while (a[i]){
            ++res;
            if (a[i / 2]) --a[i / 2];
            if (a[i / 2 * 2]) --a[i / 2 * 2];
            if (a[i / 2 * 2 + 1]) --a[i / 2 * 2 + 1];
        }
    }

    res += a[1];

    cout << res << endl;

    return 0;
}