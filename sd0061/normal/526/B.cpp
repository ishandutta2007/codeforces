#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n , a[N];
int m , b[N];
int res;
void work() {
    int i;
    scanf("%d",&m);
    n = (1 << m + 1) - 1;
    for (i = 2 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        if (i >= (1 << m))
            b[i] = a[i];
    }
    for (i = (1 << m) - 1 ; i >= 1 ; -- i) {
        res += abs(b[i << 1] - b[i << 1 | 1]);
        b[i] = max(b[i << 1] ,  b[i << 1 | 1]) + a[i];
    }
    cout << res << endl;        
}

int main() {    
    work();    
    return 0;
}