#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1002;
const int M = 1000000007;
LL c[N][N], b[N], ans = 1;

void init() {
    for (int i=0;i<N;i++) c[i][0]=1;
    for (int i=1;i<N;i++) {
        for (int j=1;j<=i;j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
        }
    }
    b[0] = b[1] = 1;
    for (int i=2;i<N;i++) {
        for (int j=0;j<i;j++) {
            b[i] = (b[i] + c[i-1][j] * b[j] % M) % M;
        }
    }
}
int n, m;
char s[52][1002];
vector<int> v[1002];
int main() {
    init();
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            v[j].push_back(s[i][j]);
        }
    }
    sort(v+1, v+1+m);
    int cur = 1;
    for (int i = 2; i <= m; i ++) {
        if (v[i] == v[i-1]) cur ++;
        if (v[i] != v[i-1] || i == m) {
            //printf("%d\n", cur);
            ans = ans * b[cur] % M; cur = 1;
        } 
    }
    printf("%lld\n", ans);
}