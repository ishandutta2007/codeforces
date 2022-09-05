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
    bool q[100005];
    CLEAR(q);
    int a,b,m,r0,r;
    cin >> a >> b >> m >> r0;
    r = r0;
    int left,right;
    int x;
    for(int i=0;;i++){
        r = (a*r + b) % m;
        if (!q[r]) q[r] = 1;
        else{
            x = r;
            right = i;
            break;
        }
    }
    for(int i=0;;i++){
        r0 = (a*r0 + b) % m;
        if (r0 == x){
            left = i;
            break;
        }
    }
    cout << right - left;
}