#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;



int main() {
    int n;
    cin >> n;
    int res = -INF;
    int a[20005];
    FOR(i,0,n)
        cin >> a[i];
    FOR(i,3,n+1)
        if (n%i == 0)
            FOR(j,0,n/i){
                int s = 0;
                for(int k=j; k<n; k += n/i)
                    s += a[k];
                res = max(res,s);
        }
    cout << res;
    return 0;
}