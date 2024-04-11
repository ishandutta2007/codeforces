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
const int F = (1<<23)-1;

int q[9000007];
int dp[9000007];
int find(int p){
    if (q[p] == 1) return p;
    FOR(i,0,23)
        if ((p&(1<<i)) && dp[p-(1<<i)]!=0) return find(p-(1<<i));
}
int main(){
    memset(q,0,sizeof(q));
    memset(dp,0,sizeof(dp));
    int n,l;
    cin >> n;
    vector<int> a;
    FOR(i,0,n){
        cin >> l;
        a.PB(l);
        q[l]=1;
        dp[l]=l;
    }
    for(int mask = 1; mask<=F; ++mask){
        FOR(t,0,24)
            if ((mask & (1<<t)) && mask>=(1<<t))
                if (dp[mask - (1<<t)]!=0)
                    dp[mask] = dp[mask - (1<<t)];
    }
    FOR(i,0,a.size()){
        int rev = F - a[i];
        if (dp[rev] == 0){
            cout << -1 << ' ';
            continue;
        }
        cout << dp[rev] << ' ';
    }
    return 0;
}