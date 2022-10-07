#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    for(int l = 1; l <= 10; ++l) {
        for(int x = 0; x < 10; ++x) {
            for(int y = x + 1; y < 10; ++y) {
                for(int btmsk = 0; btmsk < (1 << l); ++btmsk) {
                    if (x == 0 && (btmsk & 1)) continue;
                    int pc = __builtin_popcount(btmsk);
                    if (pc == 0 || pc == l) continue;
                    ll num = 0;
                    for(int i = 0; i < l; ++i) {
                        num = num * 10 + ((btmsk >> i) & 1 ? x : y);
                    }
                    if (num <= N) {
                        cnt++;
                    }
                }
            }
        }
        for(int x = 1; x < 10; ++x) {
            ll num = 0;
            for(int i = 0; i < l; ++i) {
                num = 10 * num + x;
            }
            if (num <= N) {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}