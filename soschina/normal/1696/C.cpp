#include <cstdio>
using namespace std;
const int N = 5e4 + 1;

int t, n, m, k, a[N], b[N];
long long cnt[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            cnt[i] = 1;
            while(a[i] % m == 0){
                a[i] /= m;
                cnt[i] *= m;
            }
            if(a[i] == a[i - 1]){
                cnt[i - 1] += cnt[i];
                i--, n--;
            }
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
            scanf("%d", &b[i]);
        bool flag = true;
        int p = 1;
        for (int i = 1; i <= k; i++){
            if(p > n){
                flag = false;
                break;
            }
            if(b[i] % a[p] == 0){
                int x = b[i] / a[p];
                while(x % m == 0)
                    x /= m;
                if(x != 1){
                    flag = false;
                    break;
                }
                cnt[p] -= b[i] / a[p];
                if(cnt[p] == 0){
                    p++;
                }else if(cnt[p] < 0){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        puts(flag && p > n ? "Yes" : "No");
    }
    return 0;
}