#pragma comment(linker, "/STACK:32777216")
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
#include <time.h>

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

int a[1007] , c[1007];

int main() {
    int n,k;
    cin >> n >> k;

    FOR(i,0,n)
        cin >> a[i];
    FOR(i,0,n)
        cin >> c[i];
    
    int s = 0;
    int M = c[0];
    int t = 0;
    FOR(i,0,n){
        t += a[i];
        s += c[i];
        M = max(c[i],M);
        while (s < a[i]){
            t += k;
            s += M;
        }
        s -= a[i];
    }

    cout << t << endl;

    return 0;
}