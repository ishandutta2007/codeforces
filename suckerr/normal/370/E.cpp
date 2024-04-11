#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int N = 222222;

int lower[N], upper[N];
int n, a[N], le[N], ri[N];

int main() {
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    lower[0] = upper[0] = 0;
    for(int i = 1; i <= n; i++) {
        le[i] = n + 1;
        ri[i] = -1;
    }
    
    int maxNum = -1;
    
    for(int i = 1; i <= n; i++) 
        if (a[i]) {
            if (a[i] < 1 || a[i] > n) {
                printf("-1\n");
                return 0;
            }
            int x = a[i];
            le[x] = min(le[x], i);
            ri[x] = max(ri[x], i);
            maxNum = max(maxNum, a[i]);
        }
    
    if (maxNum == -1) {
        if (n < 2) {
            printf("-1\n");
        } else {
            printf("%d\n", n / 2);
            for(int i = 1; i <= n / 2; i++) {
                a[i * 2 - 1] = a[i * 2] = i;
            }
            if (n % 2 == 1)
                a[n] = a[n - 1];
            for(int i = 1; i <= n; i++) {
                printf("%d%c", a[i], i == n ? '\n' : ' ');
            }
        }
        
        return 0;
    }
    
    for(int i = 1; i <= n; i++) {
        if (ri[i] == -1) {
            lower[i] = lower[i - 1] + 2;
            upper[i] = upper[i - 1] + 5;
        } else {
            int tmp = ri[i] - le[i] + 1;
            if (tmp > 5) {
                printf("-1\n");
                return 0;
            }
            
            if (lower[i - 1] >= le[i] || ri[i] - upper[i - 1] > 5) {
                printf("-1\n");
                return 0;
            }
            
            lower[i] = max(ri[i], lower[i - 1] + 2);
            upper[i] = min(le[i] + 4, upper[i - 1] + 5);
        }
    }
    
    int ans = 0;
    
    for(int i = maxNum; i <= n; i++) {
        if (lower[i] <= n && upper[i] >= n)
            ans = i;
    }
    
    if (ans == 0) {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n", ans);
    
    int nn = n;
    
    for(int i = ans; i >= 1; i--) {
        for(int j = 2; j <= 5; j++) {
            if (ri[i] != -1 && le[i] < nn - j + 1)
                continue;
            int tmp = nn - j;
            bool flag = true; 
            if (lower[i - 1] <= tmp && tmp <= upper[i - 1]) {
                for(int k = tmp + 1; k <= nn; k++)
                    if (a[k] && a[k] != i)
                        flag = false;
                if (!flag)
                    continue;
                for(int k = tmp + 1; k <= nn; k++)
                    a[k] = i;
                nn = tmp;
                break;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    
    return 0;
}