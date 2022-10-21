#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50, INF = (int)1e9;
typedef pair<int, int> P;


int n, a[N];
vector<int> G[N];
map<int, int> sig;
map<P, int> dob;
int dis[N], pv[N];
int pm[N], pms;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(p + 2, p + N, 1);
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            pm[pms++] = i;
            for(int j = i * 2; j < N; j += i) p[j] = 0;
        }
    }
//    cout << p[2] << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int x = -1, y = -1;
        for(int d = 1; d * d <= a[i]; d++) {
            if(a[i] % d == 0) {
                if(p[d]) {
                    if(x == -1) x = d;
                    else y = d;
                }
                if(d * d != a[i] && p[a[i] / d]) {
                    if(x == -1) x = a[i] / d;
                    else y = a[i] / d;
                }
            }
        }
        int cx = 0, cy = 0;

        if(x != -1) while(a[i] % x == 0) cx = !cx, a[i] /= x;
        if(y != -1) while(a[i] % y == 0) cy = !cy, a[i] /= y;
        assert(a[i] == 1);
        if(!cx && !cy) {
            cout << 1 << endl;
            return 0;
        }
        else if(cx && cy) {
            G[x].push_back(y);
            G[y].push_back(x);
            dob[{x, y}]++;
            dob[{y, x}]++;
        }
        else {
            if(!cx) swap(x, y);
            G[x].push_back(0);
            G[0].push_back(x);
            sig[x] += 1;
        }
    }
    for(auto p : sig) if(p.second >= 2) {
        cout << 2 << endl;
        return 0;
    }
    for(auto p : dob) if(p.second >= 2) {
            cout << 2 << endl;
            return 0;
        }

    int res = INF;
    for(int s = 0; s <= 1000; s++) {
        if(s == 0 || p[s]) {
            dis[0] = INF;
            for(int i = 0; i < pms; i++) dis[pm[i]] = INF;
            queue<int> que;
            dis[s] = 0;
            que.push(s);
            pv[s] = -1;
            while(!que.empty()) {
                int v = que.front(); que.pop();
                for(int nxt : G[v]) {
//                    cout << v << " to " << nxt << endl;
                    if(dis[nxt] == INF) {
                        dis[nxt] = dis[v] + 1;
                        pv[nxt] = v;
                        que.push(nxt);
                    }
                    else {
                        if(nxt != pv[v]) res = min(res, dis[nxt] + dis[v] + 1);
                    }
                }
            }
        }
    }
    if(res == INF) res = -1;
    cout << res << '\n';

}