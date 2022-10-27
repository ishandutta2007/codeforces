#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, k, T=0;
bool query(LL L, LL R) {
    ++ T;if(T==4501) exit(0);
    printf("%lld %lld\n", L, R);
    fflush(stdout);
    char s[10]; scanf("%s", s);
    if (s[0] == 'B') exit(0);
    if (s[0] == 'Y') {
        if(L==R) {
            exit(0);
        }
        return 1;
    }
    return 0;
}
LL myrand(LL x,LL y) {
    return x + rand()%(y-x+1);
}
void solve(LL l,LL r) {
    LL mid=(l+r)>>1;
    if(query(l,mid)) {
        LL lb = max(l-k,1LL), rb = min(mid+k,n);
        if(rb-lb >= r-l) {
            LL x = myrand(max(l-k,1LL),min(mid+k,n));
            query(x,x);
            solve(max(l-2*k,1LL),min(mid+2*k,n));
            return;
        }
        solve(max(l-k,1LL),min(mid+k,n));
    } else {
        LL lb = max(mid+1-k,1LL), rb = min(r+k,n);
        if(rb-lb >= r-l) {
            LL x = myrand(max(mid+1-k,1LL),min(r+k,n));
            query(x,x);
            solve(max(mid+1-2*k,1LL),min(r+2*k,n));
            return;
        }
        solve(max(mid+1-k,1LL),min(r+k,n));
    }
}
int main() {
    srand(time(NULL));
    cin >> n >> k;
    solve(1,n);
}