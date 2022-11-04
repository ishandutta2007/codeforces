#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N] = {1}, cnt[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans;
        for (int i = n;; i--){
            if(cnt[a[i]]){
                ans = i;
                for (int j = i + 1; j <= n; j++)
                    cnt[a[j]]--;
                break;
            }
            cnt[a[i]]++;
        }
        printf("%d\n", ans);
    }
    return 0;
}