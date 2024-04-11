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
 
const long double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;
 
int m;
 
LL** mult(LL** a,LL** b){
    LL** c = new LL*[2];
    FOR(i,0,2)
        c[i] = new LL[2];
    FOR(i,0,2)
        FOR(j,0,2)
            c[i][j] = 0;
    FOR(i,0,2)
        FOR(j,0,2)
            FOR(t,0,2)
                c[i][j] += (a[i][t] * b[t][j]) % m;
    FOR(i,0,2)
        FOR(j,0,2)
            c[i][j] %= m;
    return c;
}
 
LL** bpow(LL** a,LL k){
    if (k == 1) return a;
    if (k & 1) return mult(a,bpow(a,k - 1));
    return bpow(mult(a,a),k / 2);
}
 
int main(){
    
    int n;
    cin >> n >> m;
    
    if (n == 1){
        cout << 2 % m << endl;
        return 0;
    }

    if (n == 2){
        cout << 8 % m << endl;
        return 0;
    }

    LL ** a = new LL*[2];
    FOR(i,0,2)
        a[i] = new LL[2];

    a[0][0] = 4;
    a[0][1] = -3;
    a[1][0] = 1;
    a[1][1] = 0;

    LL ** c = bpow(a,n - 2);


    LL res = (8ll * c[0][0] + 2 * c[0][1] + 100500ll * m) % m;

    cout << res << endl;

    return 0;
}