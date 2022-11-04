#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, m, k, a[N], tmp[N], cnt[N];

int main(){
    scanf("%d", &t);
    while(t--){
        memset(cnt + 1, 0, sizeof(int) * m);
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            tmp[i] = a[i];
        }
        sort(tmp + 1, tmp + 1 + n);
        m = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
        for (int i = 1; i <= n; i++){
            a[i] = lower_bound(tmp + 1, tmp + 1 + m, a[i]) - tmp;
            cnt[a[i]]++;
        }
        int l = 1, r = 1;
        while(l <= m && cnt[l] < k)
            l++, r++;
        int ansl = 0, ansr = -1;
        while(l <= m){
            while(r < m && tmp[r + 1] == tmp[r] + 1 && cnt[r + 1] >= k)
                r++;
            if (cnt[r] >= k && r - l > ansr - ansl)
                ansl = tmp[l], ansr = tmp[r];
            l = ++r;
            while(l <= m && cnt[l] < k)
                l++, r++;
        }
        if(!ansl)
            puts("-1");
        else
            printf("%d %d\n", ansl, ansr);
    }
    return 0;
}