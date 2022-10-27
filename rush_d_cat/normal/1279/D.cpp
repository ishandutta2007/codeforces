#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
const LL MOD = 998244353;

int n,c[N];
vector<int> v[N];
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int y;scanf("%d",&y);c[y]++;
            v[i].push_back(y);
        }
    }
    LL ans = 0;
    LL p1 = mpow(n, MOD-2);
    for(int i=1;i<=n;i++){
        //if (v[i].size() == 0) continue;
        LL p2 = mpow(v[i].size(), MOD-2);
        for(auto x: v[i]) {
            ans = ans + (p1 * p2 % MOD) * (c[x] * p1 % MOD) % MOD;
            ans = ans % MOD;
        }
    }
    cout << ans << endl;
}

/*

1 1: 2 4
1 2: 1 2
2 1: 1 2
1 1: 1 1

*/