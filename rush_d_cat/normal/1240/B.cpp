#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
int T, n, a[N], L[N], R[N];

int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            L[i] = N, R[i] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            L[a[i]] = min(L[a[i]], i);
            R[a[i]] = max(R[a[i]], i);
        }
        vector< pair<int, int> > v;
        for (int i = 1; i <= n; i ++) {
            if (L[i] <= R[i]) { 
                v.push_back(make_pair(L[i], R[i]));
                // printf("! [%d, %d]\n", L[i], R[i]);
            }
        }
        int ans = 0;
        for (int i = 0, j = 0; i < v.size(); i = j) {
            j = i + 1;
            while (j < v.size() && v[j-1].second < v[j].first) j ++;
            ans = max(ans, j - i);
        }
        printf("%d\n", (int)v.size() - ans);
    }
}

/*
1 2 3 5 4 7 8 9
*/