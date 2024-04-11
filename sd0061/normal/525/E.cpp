#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30;

int n , K , a[N] , m , b[N];
LL S , p[N] , res;
map<LL , int> h[N];

void dfs(int k , int w , LL s) {
    if (w > K) return;
    if (s > S) return;
    if (k == n) {
        h[w][s] ++;
        return;
    }
    dfs(k + 1 , w , s);
    dfs(k + 1 , w , s + b[k]);
    if (b[k] < 19)
        dfs(k + 1 , w + 1 , s + p[b[k]]);
}
void DFS(int k , int w , LL s) {
    if (w > K) return;
    if (s > S) return;
    if (k == m) {
        for (int i = 0 ; i + w <= K ; ++ i)
            if (h[i].count(S - s))
                res += h[i][S - s];
        return;
    }
    DFS(k + 1 , w , s);
    DFS(k + 1 , w , s + b[k]);
    if (b[k] < 19)
        DFS(k + 1 , w + 1 , s + p[b[k]]);    
}


void work() {
    int i;
    p[0] = 1;
    for (i = 1 ; i <= 20 ; ++ i)
        p[i] = p[i - 1] * i;
    scanf("%d%d%lld" , &n , &K , &S);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        b[m ++] = a[i];
    }
    sort(b , b + m);
    n = m / 2;
    dfs(0 , 0 , 0);
    DFS(n , 0 , 0);
    cout << res << endl;
}

int main() {
    work();
    return 0;
}