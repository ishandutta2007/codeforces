#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

struct P {
    int a, b;
};

int n, k;
int p[N];
int pos[N], def[N];
int dis[N][N];
queue<P> que;
int res = 0;

void add(int a, int b, int x) {
    if(dis[a][b] != -1) return ;
    dis[a][b] = x;
    res++;
    if(x > 0) que.push({a, b});
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[i] = pos[i-1] + (p[i] > 0);
        def[i] = def[i-1] + (p[i] == 100);
    }
    memset(dis, -1, sizeof(dis));
    add(1, 2, k);
    while(!que.empty()) {
        P pi = que.front(); que.pop();
        int a = pi.a, b = pi.b;
        if(b == n + 1 || a == n + 1) continue;
        if(def[n] - def[b - 1] == 0 && p[a] > 0) add(a, b + 1, dis[a][b] - 1);
        if(pos[n] - pos[b - 1] > 0 && p[a] > 0) add(b + 1, b + 2, dis[a][b] - 1);
        if(pos[n] - pos[b - 1] > 0 && p[a] < 100) add(b, b + 1, dis[a][b] - 1);
    }
    cout << res << endl;

}