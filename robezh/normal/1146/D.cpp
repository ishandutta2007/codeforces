#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;

typedef long long ll;
bool vis[N];
queue<int> que;
int psum[N];

int n;
int a, b;
ll res = 0, cur = 0;

int main() {
    cin >> n >> a >> b;
    int lim = 4 * max(a, b) + 2;
    res = 0, cur = 0;
    vis[0] = true;

    cur ++;
    res ++;
    for(int i = 1; i <= min(n, lim); i++) {
        if(i - a >= 0 && vis[i-a]) {
            vis[i] = true;
            cur++;
            que.push(i);
        }
        else {
            res += cur;
            continue;
        }
        while(!que.empty()) {
            int v = que.front(); que.pop();
            if(v - b >= 0 && !vis[v-b]) {
                vis[v-b] = true;
                cur++;
                que.push(v-b);
            }
            if(v + a < i && !vis[v+a]) {
                vis[v+a] = true;
                cur++;
                que.push(v+a);
            }
        }
        res += cur;
    }
    int g = __gcd(a, b);
    psum[0] = 1;
    for(int i = 1; i < a; i++) psum[i] = psum[i-1] + (i % g == 0);
    assert(psum[a - 1] == a / g);
    ll t_res = 0;

    ll c_res = 0;
    if(n > lim) {
        for(int rem = 0; rem < g; rem++) {
            ll fir = (lim + 1 - rem + g - 1) / g + 1;
            ll sec = (n + 1 - rem + g - 1) / g;
            c_res += (sec + fir) * (sec - fir + 1) / 2;
        }
    }
    cout << res + c_res << endl;
}