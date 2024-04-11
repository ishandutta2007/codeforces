#include <cstdio>
using namespace std;
const int N = 1e5;

int t, n, pre[N], a[N];
bool issqr[2 * N];

int main(){
    for (int i = 0; i * i <= 2 * N; i++)
        issqr[i * i] = true;
    for (int i = 0; i < N; i++){
        if(issqr[i]){
            pre[i] = -1;
            continue;
        }
        for (int j = i - 1; j >= 0; j--){
            if(issqr[j + i + 1]){
                pre[i] = j;
                break;
            }
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int m = n;
        n--;
        while(n != -1){
            int m = pre[n] + 1;
            for (int i = n; i >= m; i--)
                a[i] = n - i + m;
            n = pre[n];
        }
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }
    return 0;
}