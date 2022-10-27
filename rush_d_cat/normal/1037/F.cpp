#include <iostream>
using namespace std;
const int N = 1000000 + 10;
typedef long long LL;
const LL MOD = 1e9 + 7;
int n, k;
int a[N],pre[N],nex[N];
int stk[N],top;
LL getAns(LL x) {
    if(x<k) return 0;
    LL c = (x-k)/(k-1)+1;
    LL a1 = (x-k+1);
    LL len = (x-k)/(k-1) * (k-1) + k;
    LL ac = x-len+1;
    return c*(a1+ac)/2;
}
LL solve(int pos,int L,int R) {
    return getAns(R-L-1)-getAns(pos-L-1)-getAns(R-pos-1);
}
int main() {
    scanf("%d%d",&n,&k); for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        while(top && a[stk[top]]<=a[i]) top--;
        pre[i] = stk[top], stk[++top] = i;
    }
    top=0; stk[top]=n+1;
    for(int i=n;i>=1;i--) {
        while(top && a[stk[top]]<a[i]) top--;
        nex[i] = stk[top], stk[++top] = i;
    }

    LL ans = 0;
    for(int i=1;i<=n;i++) {
        ans = ans + solve(i, pre[i], nex[i]) % MOD * a[i] % MOD;
        ans = ans % MOD;
    }
    cout << ans << endl;
}