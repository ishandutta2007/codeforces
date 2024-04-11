#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
const int N = 200005;
typedef long long LL;
using namespace std;
int n , a[N] , mx[N] , R[N + N];
bool f[N];
vector<int> GCD[N];
void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        GCD[__gcd(i , n)].push_back(i);
        scanf("%d" , &a[i - 1]);
    }
    LL res = 0;
    for (int d = 1 ; d < n ; ++ d) {
        if (n % d == 0) {
            for (int i = 0 ; i < d ; ++ i)
                mx[i] = -1 << 30;
            for (int i = 0 ; i < n ; ++ i)
                mx[i % d] = max(mx[i % d] , a[i]);
            for (int i = 0 ; i < n ; ++ i)
                f[i] = (a[i] == mx[i % d]);
            for (int i = n + n - 1 ; i >= 0 ; -- i) {
                if (f[i % n])
                    R[i] = R[i + 1] + 1;
                else
                    R[i] = 0;                
            }
            for (int i = 0 ; i < n ; ++ i) {
                int p = min(R[i] , n);
                res += upper_bound(GCD[d].begin() , GCD[d].end() , p) - GCD[d].begin();
            }            
        }
    }
    printf("%lld\n" , res);    
}


int main() {
    work();
    return 0;
}