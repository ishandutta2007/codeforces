#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111;
const int INF = 1000000000;

int n, a[N], cnt[N], b[N];

int check(int r) {
    for(int i = 1; i <= r; i++)
        b[i] = INF;
    int c = n;
    while(c) {
        for(int i = 1; c && i <= r; i++) {
            if (b[i] <= 0)
                return 0;
            b[i] = min(b[i] - 1, a[c]);
            c--;
        }
    }
    
    return 1;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a + 1, a + n + 1);
    
    int l = 1, r = n, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    
    printf("%d\n", l);
    
    return 0;
}