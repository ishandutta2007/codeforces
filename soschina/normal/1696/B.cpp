#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] == 0){
                ans += (bool)cnt;
                cnt = 0;
            }
            else
                cnt++;
        }
        ans += (bool)cnt;
        printf("%d\n", min(ans, 2));
    }
    return 0;
}