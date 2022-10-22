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
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        auto check = [&](vector<int> a, int x) {
            int n = a.size();
            int n1 = 0, n2 = n - 1;
            while(n1 < n2) {
                if (a[n1] == a[n2]) {
                    n1++;
                    n2--;
                } else if (a[n1] == x) {
                    n1++;
                } else if (a[n2] == x) {
                    n2--;
                } else {
                    return false;
                }
            }
            return true;
        };
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[n - 1 - i]) {
                ok = (check(a, a[i]) || check(a, a[n - 1 - i]));
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}