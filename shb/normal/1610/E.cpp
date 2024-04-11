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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int ans = 0;
        for (auto &t : cnt) {
            int a0 = t.first;
            int sum = t.second;
            int last = a0;
            while(true) {
                int mi = max(2 * last - a0, last + 1);
                auto it = cnt.lower_bound(mi);
                if (it == cnt.end()) break;
                last = it -> first;
                //sum += it -> second;
                sum++;
            }
            //printf("%d %d\n",t.first,sum);
            ans = max(ans, sum);
        }
        printf("%d\n",n - ans);
    }
}