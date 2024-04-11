#include<bits/stdc++.h>
using namespace std;
 
#define N 200010
 
vector <int> v[N];
 
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        int x, step = 0;
        scanf("%d", &x);
        while(1) {
            v[x].push_back(step);
            if(x == 0) break;
            x >>= 1, step ++;
        }
    }
    int ans = 1e9;
    for(int i = 0; i < N; i ++) if(v[i].size() >= k) {
        sort(v[i].begin(), v[i].end());
        int sum = 0;
        for(int j = 0; j < k; j ++) sum += v[i][j];
        ans = min(ans, sum);
    }
    cout << ans << endl;
}