#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int INF = 10000000;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    int b[60] {0};
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        if(a[i] == 0){
            i--;
            n--;
            continue;
        }
        for(int j = 0; j < 60; j++){
            if((1ll << j) & a[i]) b[j]++;
            if(b[j] >= 3){
                cout << 3 << endl;
                return 0;
            }
        }
    }
    int g[300][300];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = 0;
            if(a[i] & a[j]) g[i][j] = 1;
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++){
        queue<int> que;
        int d[300];
        fill(d, d + n, INF);
        int pre[300];
        fill(pre, pre + n, -1);
        que.push(i);
        d[i] = 0;
        pre[i] = i;
        bool f = false;
        while(que.size()){
            int now = que.front();
            que.pop();
            for(int next = 0; next < n; next++){
                if(next == now || next == pre[now]) continue;
                if(g[now][next]){
                    if(d[next] != INF){
                        ans = min(ans, d[now] + d[next] + 1);
                        f = true;
                        break;
                    }
                    d[next] = d[now] + 1;
                    pre[next] = now;
                    que.push(next);
                }
            }
            if(f) break;
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}