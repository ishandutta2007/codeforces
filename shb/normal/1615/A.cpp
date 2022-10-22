#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        LL S = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            S += a[i];
        }
        LL mi = S / n;
        LL mo = S % n;
        if (mo) puts("1");
        else puts("0");
    }
}