#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1002;
int T, n, ans[N];
struct Item {
    int id, l, r;
} it[N];
bool cmp(Item A, Item B) {
    if (A.l == B.l)
        return A.id < B.id;
    return A.l < B.l;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i ++) {
            it[i].id = i;
            scanf("%d %d", &it[i].l, &it[i].r);
        }
        sort(it + 1, it + 1 + n, cmp);
        
        int ti = 1;
        for (int i = 1; i <= n; i ++) {
            if (it[i].l >= ti)
                ti = it[i].l;
            
            if (it[i].r >= ti) {
                ans[it[i].id] = (ti ++);
            }
        }
        for (int i = 1; i <= n; i ++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}