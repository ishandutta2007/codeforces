#include <bits/stdc++.h>

using namespace std;

int n, a[100010], pos[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        reverse(a+1,a+n+1);
        set<int>s;
        for (int i=1;i<=n;i++) {
            s.insert(i);
            pos[a[i]] = i;
        }
        int now = 1;
        while(now <= n) {
            int max_val = (*s.rbegin());
            int max_pos = pos[max_val];
            reverse(a+now,a+max_pos+1);
            for (int i=now;i<=max_pos;i++) {
                s.erase(a[i]);
            }
            now = max_pos + 1;
        }
        for (int i=1;i<=n;i++) {
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
}