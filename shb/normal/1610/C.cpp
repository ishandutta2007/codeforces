#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int>a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
        int L = 0, R = n + 1;
        while(L < R - 1) {
            int A = (L + R) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] < A - a[i] - 1) {
                    continue;
                }
                if (cnt > b[i] || cnt < A - a[i] - 1) continue;
                cnt++;
            }
            if (cnt >= A) {
                L = A;
            } else {
                R = A;
            }
        }
        printf("%d\n",L);
    }    
}