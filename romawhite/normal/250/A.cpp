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
    int a[105];
    FOR(i,0,n)
        cin >> a[i];

    int k = 0;
    int t = 0;
    vector<int> res;
    FOR(i,0,n){
        if (k == 2 && a[i] < 0){
            res.PB(t);
            k = 0;
            t = 0;
        }
        if (a[i] < 0) ++k;
        ++t;
    }

    res.PB(t);
    cout << res.size() << endl;
    FOR(i,0,res.size())
        cout << res[i] << ' ';
    return 0;
}