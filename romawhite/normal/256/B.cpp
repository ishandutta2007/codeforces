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

const double pi = acos(-1.0);
const int INF=1000000000;
const LL mod= 1000000007;

LL n,c;
LL X,Y;

bool f(LL x){
  //  cout <<x <<'x' << endl; 
    LL r = 0;
    if (X - 1 + Y - 1 > x){
        LL h = max(X - 1 - x , 0ll);
        LL w = max(Y - 1 - x , 0ll);
        r += h * (Y - 1) + w * (X - 1) - w * h;
        LL st = x - max(x - X + 1 , 0ll) - max(x - Y + 1 , 0ll);
        r += st * (st + 1) / 2;
        r += h + w;
    }

   // cout << r << endl;
    if (n - X + Y - 1 > x){
        LL h = max(n - X - x , 0ll);
        LL w = max(Y - 1 - x , 0ll);
        r += h * (Y - 1) + w * (n - X) - w * h;
        LL st = x - max(x - n + X , 0ll) - max(x - Y + 1 , 0ll);
        r += st * (st + 1) / 2;
    }

   // cout << r << endl;

    if (n - X + n - Y > x){
        LL h = max(n - X - x , 0ll);
        LL w = max(n - Y - x , 0ll);
        r += h * (n - Y) + w * (n - X) - w * h;
        LL st = x - max(x - n + X , 0ll) - max(x - n + Y , 0ll);
        r += st * (st + 1) / 2;
        r += w + h;
    }

   // cout << r << endl;

    if (X - 1 + n - Y > x){
        LL h = max(X - 1 - x , 0ll);
        LL w = max(n - Y - x , 0ll);
        r += h * (n - Y) + w * (X - 1) - w * h;
         LL st = x - max(x - X + 1 , 0ll) - max(x - n + Y , 0ll);
        r += st * (st + 1) / 2;
    }

    //cout << r << endl;

    if (n * n - r < c) return 0;
    return 1;
}

int main(){
    cin >> n;
    cin >> X >> Y >> c;
    int L = 0;
    int R = 2 * n;
    while (R - L > 1){
        LL X = (L + R) / 2;
        if (f(X)) R = X;
        else L = X;
    }

    if (f(L)) R = L;

    cout << R << endl;

    return 0;
}