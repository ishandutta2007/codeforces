#include <cstdio>
#include <cstring>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N], cnt[N];

int tree[N];
void add(int i){
    while(i <= n){
        tree[i]++;
        i += lowbit(i);
    }
}
int sum(int i){
    int ret = 0;
    while(i){
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(tree + 1, 0, sizeof(int) * n);
        memset(cnt + 1, 0, sizeof(int) * n);
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
            ans += i - 1 - sum(a[i]);
            add(a[i]);
        }
        for (int i = 1; i <= n; i++)
            ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}