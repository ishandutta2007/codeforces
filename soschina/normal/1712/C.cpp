#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];
bool to0[N];

int main(){
    scanf("%d", &t);
    while(t--){
        memset(to0 + 1, 0, sizeof(bool) * n);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int p = 0;
        for (int i = n - 1; i >= 1; i--){
            if(a[i] > a[i + 1]){
                p = i;
                break;
            }
        }
        if(!p){
            puts("0");
            continue;
        }
        for (int i = p; i >= 1; i--)
            to0[a[i]] = true;
        for (int i = n; i > p; i--){
            if(to0[a[i]]){
                p = i;
                break;
            }
        }
        int ans = 0;
        memset(to0 + 1, 0, sizeof(bool) * n);
        for (int i = 1; i <= p; i++){
            if(!to0[a[i]]){
                to0[a[i]] = true;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}