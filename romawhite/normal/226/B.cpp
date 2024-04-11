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
 
vector<LL> a;
 
int main(){
    
    int n;
    cin >> n;
    a.resize(n);
    FOR(i,0,n)
        cin >> a[i];

    sort(ALL(a));
    reverse(ALL(a));

    vector<LL> s(n + 1);

    s[0] = 0;
    FOR(i,1,n + 1)
        s[i] = s[i - 1] + a[i - 1];

    LL res1 = 0;
    FOR(i,0,n)
        res1 += i * a[i];

    int q;
    cin >> q;

    FOR(i,0,q){
        LL k;
        cin >> k;
        if (k == 1){
            cout << res1 << ' ';
            continue;
        }
        LL res = 0;
        LL d = k;
        LL l = 1;
        while(l < n){
            res += (s[n] - s[l]);
            l += d;
            d *= k;
        }
        cout << res << ' ';
    }

    return 0;
}