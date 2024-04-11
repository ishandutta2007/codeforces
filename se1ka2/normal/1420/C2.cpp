#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        ll a[300005];
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if((i == 0 || a[i] > a[i - 1]) && (i == n - 1 || a[i] > a[i + 1])) ans += a[i];
            if((i != 0 && a[i] < a[i - 1]) && (i != n - 1 && a[i] < a[i + 1])) ans -= a[i];
        }
        printf("%lld\n", ans);
        while(q--){
            int l, r;
            scanf("%d %d", &l, &r);
            l--; r--;
            if(l > 0){
                if(a[l - 1] < a[l] && a[l - 1] > a[r]){
                    ans += a[l - 1];
                }
                if(a[l - 1] > a[l] && a[l - 1] < a[r]){
                    ans -= a[l - 1];
                }
            }
            if(l < n - 1){
                if(a[l + 1] < a[l] && a[l + 1] > a[r]){
                    ans += a[l + 1];
                }
                if(a[l + 1] > a[l] && a[l + 1] < a[r]){
                    ans -= a[l + 1];
                }
            }
            if(r > 0){
                if(a[r - 1] < a[r] && a[r - 1] > a[l]){
                    ans += a[r - 1];
                }
                if(a[r - 1] > a[r] && a[r - 1] < a[l]){
                    ans -= a[r - 1];
                }
            }
            if(r < n - 1){
                if(a[r + 1] < a[r] && a[r + 1] > a[l]){
                    ans += a[r + 1];
                }
                if(a[r + 1] > a[r] && a[r + 1] < a[l]){
                    ans -= a[r + 1];
                }
            }
            if((l == 0 || a[l] > a[l - 1]) && (l == n - 1 || a[l] > a[l + 1])) ans -= a[l];
            if((l != 0 && a[l] < a[l - 1]) && (l != n - 1 && a[l] < a[l + 1])) ans += a[l];
            if((r == 0 || a[r] > a[r - 1]) && (r == n - 1 || a[r] > a[r + 1])) ans -= a[r];
            if((r != 0 && a[r] < a[r - 1]) && (r != n - 1 && a[r] < a[r + 1])) ans += a[r];
            swap(a[l], a[r]);
            if((l == 0 || a[l] > a[l - 1]) && (l == n - 1 || a[l] > a[l + 1])) ans += a[l];
            if((l != 0 && a[l] < a[l - 1]) && (l != n - 1 && a[l] < a[l + 1])) ans -= a[l];
            if((r == 0 || a[r] > a[r - 1]) && (r == n - 1 || a[r] > a[r + 1])) ans += a[r];
            if((r != 0 && a[r] < a[r - 1]) && (r != n - 1 && a[r] < a[r + 1])) ans -= a[r];
            printf("%lld\n", ans);
        }
    }
}