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
    cin >> n;
    FOR(i,0,n)
        cin >> a[i];
    cin >> m;
    FOR(i,0,m)
        cin >> b[i];
    int M = -1;
    FOR(i,0,n)
        FOR(j,0,m)
            if (b[j] % a[i] == 0)
                M = max(M,b[j] / a[i]);
    int res = 0;
    FOR(i,0,n)
        FOR(j,0,m)
            if (b[j] % a[i] == 0 && b[j] / a[i] == M)
                ++res;
    cout << res;
    return 0;
}