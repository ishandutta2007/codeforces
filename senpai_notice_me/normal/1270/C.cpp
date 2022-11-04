#include <bits/stdc++.h>

using namespace std;

int main() {
    int case_cnt; scanf("%d", &case_cnt);
    while (case_cnt--) {
        int n; scanf("%d", &n);
        
        long long sum = 0, xor_sum = 0;
        
        for (int i = 1; i <= n; ++i) {
            static int x;
            
            scanf("%d", &x);
            sum += x;
            xor_sum ^= x;
        }
        
        if (sum == 2 * xor_sum) {
            puts("0\n");
            continue;
        }
        
        long long t = ((1LL << 50) - 2) ^ xor_sum;
        
        long long k = ((xor_sum ^ t) * 2 - (sum + t)) / 2;
        
        printf("3\n%lld %lld %lld\n", t, k, k);
    }
    
    return 0;
}