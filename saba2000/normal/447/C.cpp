#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int a[MAXN];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n;
    while (~ scanf ("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", a+i+1);
        }
        a[0] = -1;
        int ans = 0, tmp = 0;
        int pre = 1, next = 1;
        bool flag = true;
        vector <pair <int, int> >vec;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[i-1]) {
                next = i;
                if (i == n) {
                    vec.push_back(make_pair(pre, next));
                }
            } else {
                vec.push_back(make_pair(pre, next));
                if (i == n){
                    vec.push_back(make_pair(n ,n));
                }
                pre = i;
                next = i;
            }
        }
//        for (int i = 0; i < vec.size(); i++)
//        {
//            printf("%d %d\n", vec[i].first, vec[i].second);
//        }
        int siz = vec.size();
        ans = vec[0].second - vec[0].first + 2;
        for (int i = 1; i < vec.size(); i++) {
            int u = vec[i-1].first;
            int v = vec[i-1].second;
            int x = vec[i].first;
            int y = vec[i].second;

            if (x == y) {
                ans = max(ans, y-x+1 + v-u+1);
            } else {
                if (u == v) {
                    ans = max(ans, y-x+1 + v-u+1);
                } else if (a[x] > a[v-1]+1 || a[v] < a[x+1]-1) {
                    ans = max(ans, y-x+1 + v-u+1);
                } else {
                    ans = max(ans, y-x+1 + 1);
                }
            }
        }
        printf("%d\n", min(ans, n));
    }
    return 0;
}