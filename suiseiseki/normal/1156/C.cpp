
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
namespace fastIO {
#define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror) return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
#undef BUF_SIZE
};
using namespace fastIO;
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxN = 2e5 + 7;
int N, Z, a[maxN];
bool solve(int nn)
{
    for(int i=1; i<=nn; i++) if(a[N - nn + i] - a[i] < Z) return false;
    return true;
}
int main()
{
    scanf("%d%d", &N, &Z);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + N);
    int L = 0, R = N>>1, mid = 0, ans = 0;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(solve(mid))
        {
            L = mid + 1;
            ans = mid;
        }
        else R = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}