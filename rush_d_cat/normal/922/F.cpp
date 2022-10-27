#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000+10;
LL f[N], sum[N];
bool ispri(int x) {
    for (int i = 2; i * i <= x; i ++) 
        if (x % i == 0) return 0;
    return 1;
}
void init() {
    for (int i = 1; i < N; i ++) 
        for (int j = i; j < N; j += i)
            f[j] ++;

    for (int i = 1; i < N; i ++) {
        sum[i] = sum[i-1] + f[i]; 
    }   
    for (int i = 1; i < N; i ++) {
        sum[i] = sum[i] - i;
    }
}
LL n, k;

int main() {
    init();
    cin >> n >> k;
    if (sum[n] < k) return !printf("No\n");
    
    int p = 1; for (p = 1; p <= n && sum[p] < k; p ++);
    
    if (sum[p] == k) {
        printf("Yes\n%d\n", p);
        for (int i = 1; i <= p; i ++) printf("%d ", i);
        return 0;
    }
    // [1,p]

    for (int i = 1; i <= p; i ++) {
        if (sum[p] - (f[i]+(p/i)-2) == k) {
            printf("Yes\n%d\n", p-1);
            for (int j = 1; j <= p; j ++) 
                if (j != i) printf("%d ", j);
            return 0;            
        }
    } 
    int pri;
    for (pri = p; ispri(pri) == 0; pri --);

    for (int i = 1; i <= p; i ++) {
        if (sum[p] - (f[i]+p/i-2) == k+1) {
            printf("Yes\n%d\n", p-2);
            for (int j = 1; j <= p; j ++) 
                if (j != i && j != pri) printf("%d ", j);
            return 0;            
        }
    } 
    printf("No\n");
}