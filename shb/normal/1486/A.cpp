#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
        }
        for (int i=1;i<N;i++) {
            if (a[i] > i - 1) {
                LL d = a[i] - (i - 1);
                a[i] -= d;
                a[i + 1] += d;
            }
        }
        bool ok = true;
        for (int i=1;i<N;i++) {
            if (a[i] >= a[i + 1]) {
                ok = false;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}