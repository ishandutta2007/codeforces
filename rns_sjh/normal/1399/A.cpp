#include<bits/stdc++.h>
using namespace std;

#define N 110

int a[N];

set<int> s;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        int k = 2e9;
        int m = 0;
        s.clear();
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
            k = min(k, a[i]);
            m = max(m, a[i]);
        }
        bool flag = 0;
        for(int i = k; i <= m; i ++) if(!s.count(i)) {
            puts("NO");
            flag = 1;
            break;
        }
        if(flag == 0) puts("YES");
    }
}