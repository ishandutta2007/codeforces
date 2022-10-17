#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long LL;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define vec(i) for (int i = 0; i < len; ++i)
#define clr(a,b)  memset((a),b,sizeof(a))
using namespace std;
inline int Read(){
    LL s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9')   { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { s = (s << 3) + (s << 1) + (ch ^ 48); ch = getchar(); }
    return s * w;
}
const int MX = 100010;
LL dp[MX],a[MX], b[MX], N;
void init() {
    N = Read();
    rep(i, 1, N) a[i] = Read(), b[i] = a[i];
}
void solve() {
    sort(b + 1, b + 1 + N);
    rep(i, 1, N) 
        rep(j, 1, N){
            if(j == 1) dp[j] += abs(a[i] - b[j]);
            else dp[j] = min(dp[j - 1], dp[j] + abs(a[i] - b[j]));
        }
    printf("%lld\n", dp[N]);
}
int main() {
    init();
    solve();
    return 0;
}