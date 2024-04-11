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

int n,k;

bool f(ll v){
    ll vv=0;
    ll k1=1;
    for(;;){
        ll q = v/k1;
        if (q==0)break;
        vv+=q;
        k1*=k;
    }
    if (vv>=n) return 1;
    else return 0;
}

int bsearch(int l,int r){
    if (f(l)) return l;
    if (r-l==1) return r;
    int x = (l+r)/2;
    if (f(x)) return bsearch(l,x);
    else return bsearch(x,r);
}

int main() {
    cin >> n >> k;
    cout << bsearch(0,1000000001);
    return 0;
}