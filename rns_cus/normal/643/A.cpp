#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define N 5100
int a[N], deg[N];
pi ans;
int Ans[N];
short int gas[N][N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            gas[i][j] = gas[i][j - 1];
            if(a[j] == i) gas[i][j] ++;
        }
    }
    for(int i = 1; i <= n; i ++) {
        ans = pi(1, -a[i]);
        Ans[-ans.second] ++;
        for(int j = i + 1; j <= n; j ++) {
            int x = a[j];
            int num = gas[x][j] - gas[x][i - 1];
            pi b = pi(num, -x);
            if(ans < b) ans = b;
            Ans[-ans.second] ++;
        }
    }
    //for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) printf("%d %d %d %d\n", i, j, ans[i][j].first, ans[i][j].second);
    for(int i = 1; i <= n; i ++) printf("%d ", Ans[i]);
    return 0;
}