#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
struct Item {
    int l, r;
    bool operator < (const Item& o) const {
        return r < o.r;
    }
} it[N];

int n;

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        int x, w;
        scanf("%d %d", &x, &w);
        it[i].l = x - w;
        it[i].r = x + w;
    }
    sort(it+1,it+1+n);
    int ans = 0, las = -1e9;
    for(int i=1;i<=n;i++) {
        if (it[i].l >= las) {
            ans ++;
            las = it[i].r;
        }
    }
    printf("%d\n", ans);
}