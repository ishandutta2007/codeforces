#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n,k,a,b;
int A[N];
unordered_map<int,LL> dp;
int count(int x) {
    return upper_bound(A+1,A+1+k, x) - A - 1;
}
LL cac(int l,int r,int rt) {
    if(dp[rt]) return dp[rt];

    int mid=(l+r)>>1;
    int na = count(r) - count(l-1);
    LL ans;
    if (na == 0) ans = a; else ans = 1LL * b * na * (r-l+1);
    if (l==r || na==0) return dp[rt] = ans;
    //printf("[%d, %d] %lld\n", l,r,min(ans, cac(l,mid,rt<<1) + cac(mid+1,r,rt<<1|1)));
    return dp[rt] = min(ans, cac(l,mid,rt<<1) + cac(mid+1,r,rt<<1|1));
}
int main() {
    scanf("%d%d%d%d",&n,&k,&a,&b);
    for(int i=1;i<=k;i++){
        scanf("%d",&A[i]);
    }
    sort(A+1,A+1+k);
    cout << cac(1,1<<n,1) << endl;
}