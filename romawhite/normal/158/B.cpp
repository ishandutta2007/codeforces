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
    int n,k;
    int a[5];
    memset(a,0,sizeof(a));
    cin >> n;
    FOR(i,0,n){
        cin >> k;
        a[k]++;
    }
    int res = 0;
    res += a[4];
    a[4] = 0;
    res += a[3];
    a[1]-=a[3];
    a[3] = 0;
    if (a[1]<0) a[1] = 0;
    res += a[2]/2;
    if (a[2]%2 == 1){
        res++;
        a[1]-=2;
    }
    if (a[1]<0) a[1] = 0;
    res += a[1]/4;
    if (a[1] % 4 !=0)
        res++;
    cout << res;
    return 0;
}