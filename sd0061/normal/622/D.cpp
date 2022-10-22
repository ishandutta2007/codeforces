#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 998244353;

int n , a[N];

void work() {
    cin >> n;
    for (int i = 1 ; 2 * i - 1 < n ; ++ i) {
        a[i] = a[n + 1 - i] = 2 * i - 1;
    }
    for (int i = 1 ; 2 * i < n ; ++ i) {
        a[n + i] = a[n + i + (n - i - i)] = i + i;        
    }
    for (int i = 1 ; i <= n + n ; ++ i) {
        if (!a[i]) a[i] = n;
        printf("%d%c" , a[i] , " \n"[i == n + n]);
    }
    
}
 
int main() {
    work();
    return 0;
}