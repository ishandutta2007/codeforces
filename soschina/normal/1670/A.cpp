#include <cstdio>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], cnt;

int main(){
    scanf("%d", &t);
    while(t--){
        cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] < 0){
                a[i] = -a[i];
                cnt++;
            }
        }
        for (int i = 1; i <= cnt; i++)
            a[i] = -a[i];
        bool flag = true;
        for (int i = 1; i < n; i++)
            if(a[i] > a[i + 1])
                flag = false;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}