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
#include <time.h>
#include <sstream>
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
#define FILL(a,value) memset(a,value,sizeof(a))

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

const double pi = acos(-1.0);
const int INF=1000000007;
const LL mod= 1000000007;
const double EPS=1e-7;

LL n , t;

LL C[60][60];

int main(){
    //freopen("mirrors.in","r",stdin);freopen("mirrors.out","w",stdout);

    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;
    FOR(i,2,60)
        FOR(j,0,i + 1){
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }

    cin >> n >> t;

    if (t & (t - 1)){
        cout << 0 << endl;
        return 0;
    }
    
    int c = 0;
    while (t){
        t /= 2;
        ++c;
    }

    ++n;
    LL n1 = n;
    int l = 0;
    vector<int> a;
    while (n1){
        a.PB(n1 % 2);
        n1 /= 2;
        ++l;
    }
    reverse(ALL(a));

    LL res = 0;
    if (l - 1 >= c){
        res += C[l - 1][c];
    }

    //cout << res << endl;
    //cout << l << ' ' << c << endl;

    int t = 0;
    FOR(i,0,a.size()){
        if (a[i]) ++t;
        if (i < a.size() && a[i + 1] == 1){
            if (t <= c && t + l - i - 2 >= c)
                res += C[l - i - 2][c - t];
        }
    }

    if (t == c) ++res;

    //cout << res << endl;

    if (c == 1) --res;

    cout << res << endl;

    return 0;
}