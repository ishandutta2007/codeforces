#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<pi> v;
#define N 210000
pi B[N], A[N];
int id[N], st[N], len[N];
#define inf 1000000000
map<int, int> M[N];
map<int, int> :: iterator it;
int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d", &A[i].first, &A[i].second);
    }
    A[++n] = pi(-inf, 0);
    sort(A + 1, A + n + 1);
    M[1][A[1].first] = 0;
    for(int i = 1; i < n; i ++) {
        for(it = M[i].begin(); it != M[i].end(); it ++) {
            int x = it->first;
            int y = it->second;
            int en = x;
            for(int j = i + 1; j <= n; j ++) {
                for(int k = 0; k < 2; k ++) {
                    int val = A[j].first + k * A[j].second;
                    en = max(en, val);
                    M[j][en] = max(M[j][en], y + min(A[j].second, val - x) + en - val);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(it = M[i].begin(); it != M[i].end(); it ++) ans = max(ans, it->second);
    }
    printf("%d\n", ans);
    return 0;
}