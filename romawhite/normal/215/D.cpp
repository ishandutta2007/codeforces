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
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;
 
int a[100],b[100];
 
int main(){
    int n,m;
    cin >> n >> m;
    LL res = 0;
    FOR(i,0,n){
        LL t,T,x,cost;
        cin >> t >> T >> x >> cost;
        if (T <= t){
            res += cost + x * LL(m);
            continue;
        }
        LL k1 = cost + x * LL(m);
        LL k2 = cost * ((m + T - t - 1) / (T - t));
        res += min(k1,k2);
    }
    cout << res << endl;
    return 0;
}