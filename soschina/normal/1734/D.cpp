#include <cstdio>
#include <iostream>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 1;
typedef pair<long long, long long> duo;

int t, n, k, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(k == 1 || k == n){
            puts("YES");
            continue;
        }
        bool flag = true;
        int l = k, r = k;
        long long lenow = 0, lemax = 0, rinow = 0, rimax = 0, mid = a[k];
        while(l > 1 && r < n && flag){
            flag = false;
            while(l > 1 && mid + rimax + lenow + a[l - 1] >= 0){
                flag = true;
                lenow += a[--l];
                lemax = max(lenow, lemax);
            }
            while(r < n && mid + lemax + rinow + a[r + 1] >= 0){
                flag = true;
                rinow += a[++r];
                rimax = max(rinow, rimax);
            }
        }
        puts(l == 1 || r == n ? "YES" : "NO");
    }
    return 0;
}