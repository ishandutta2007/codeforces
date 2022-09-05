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

bool used[107];
int cost[107];

int top[100007];
int bot[100007];

int main() {
    cout << 307 << endl;

    cout << 0 << ' ' << 1000000 << endl;

    int x = 35000;
    int r = 305;
    while (r > 0){
        cout << x << ' ' << r << endl;
        x += r + r - 1;
        r--;
    }

    cout << 1000000 << ' ' << 1000000 << endl;

    return 0;
}