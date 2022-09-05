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
 
int main(){
    LL n,m,s;
    cin >> n >> m >> s;
    LL res = 0;
    if (s % 2 == 0){
        cout << 0;
        return 0;
    }
    FOR(i,1,s + 1)
        if (s % i == 0){
            if (n >= i && m >= s/i){
                res += (n - i + 1) * (m - s/i + 1) * (2ll * ((i + 1) / 2) * ((s/i + 1) / 2) - 1ll); 
            }
        }
    FOR(a,0,max(n,m))
        FOR(b,0,max(n,m)){
            LL S = s - (2 * a + 1)*(2 * b + 1);
            if (S <= 0) continue;
            //cout << S <<endl;
            S /= 2ll;
            FOR(i,1,2 * b + 1)
                if (i % 2 == 1 && S % i == 0){
                    LL c = a + S / i;
                    //cout << a << ' ' << b << ' ' << i << ' ' << c << endl;
                    if (2 * b + 1 <= n && 2 * c + 1 <= m)
                        res += (n - 2ll * LL(b)) * (m - 2ll * LL(c));
                    /*if (2 * b + 1 <= m && 2 * c + 1 <= n && (a != i / 2 || b != c))
                        res += 2ll * (m - 2ll * LL(b)) * (n - 2ll * LL(c));*/
                    /*if (res == 6){
                        cout << a << ' ' << b << ' ' << i << ' ' << c << endl;
                    }*/
                    //cout << res << endl;
                }
            FOR(i,1,2 * a + 1)
                if (i % 2 == 1 && S % i == 0){
                    LL c = b + S / i;
                    if (2 * c + 1 <= m && 2 * a + 1 <= n){
                        res += (m - 2ll * LL(c)) * (n - 2ll * LL(a));
                        //cout << c << ' ' << b << ' ' << a <<  endl;
                    }
                }

    }
    cout << res << endl;
    return 0;
}