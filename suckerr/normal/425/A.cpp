#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 222;
const int INF = 11111111;

int n, k;
int a[N];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = -INF;
    for(int l = 1; l <= n; l++) {
        for(int r = l; r <= n; r++) {
            vector<int> inside, outside;
            int res = 0;
            for(int i = 1; i <= n; i++) {
                if (l <= i && i <= r) {
                    inside.push_back(a[i]);
                    res += a[i];
                } else {
                    outside.push_back(a[i]);
                }
            }
            sort(inside.begin(), inside.end());
            sort(outside.begin(), outside.end());
            ans = max(ans, res);
            for(int i = 0; i < k && i < (int)inside.size() && i < (int)outside.size(); i++) {
                res -= inside[i];
                res += outside[(int)outside.size() - i - 1];
                ans = max(ans, res);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}