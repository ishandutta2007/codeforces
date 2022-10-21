#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, B = 20;
typedef long long ll;

int n;
int num[N];
ll sum[N][B][2];
vector<int> G[N];
ll res = 0;

ll C2(ll x) {return x * (x - 1) / 2;}

void dfs(int v, int p) {
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        for(int b = 0; b < 20; b++) {
            sum[v][b][0] += sum[nxt][b][0];
            sum[v][b][1] += sum[nxt][b][1];
        }
    }
    for(int b = 0; b < 20; b++) {

        ll add = 0;
        if((num[v] >> b) & 1) {
            add += C2(sum[v][b][0]) + C2(sum[v][b][1]);
            add += sum[v][b][0] + 1;
            for(int nxt : G[v]) if(nxt != p) add -= C2(sum[nxt][b][0]) + C2(sum[nxt][b][1]);
        }
        else {
            add += sum[v][b][0] * sum[v][b][1];
            add += sum[v][b][1];
            for(int nxt : G[v]) if(nxt != p) add -= sum[nxt][b][0] * sum[nxt][b][1];
        }
        res += add * (1 << b);
    }
    for(int b = 0; b < 20; b++) {
        if((num[v] >> b) & 1) {
            swap(sum[v][b][0], sum[v][b][1]);
            sum[v][b][1] ++;
        }
        else sum[v][b][0] ++;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << res << endl;

}