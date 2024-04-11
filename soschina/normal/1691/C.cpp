#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 2;

int t, n, k;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%s", &n, &k, s + 1);
        for (int i = n; i + k >= n && i > 0; i--)
            if(s[i] == '1'){
                swap(s[i], s[n]);
                k -= n - i;
                break;
            }
        for (int i = 1; i <= k + 1 && i < n; i++)
            if(s[i] == '1'){
                swap(s[i], s[1]);
                k -= i - 1;
                break;
            }
        int ans = 0;
        for (int i = 2; i < n; i++)
            if(s[i] == '1')
                ans += 11;
        if(s[1] == '1')
            ans += 10;
        if(s[n] == '1')
            ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}