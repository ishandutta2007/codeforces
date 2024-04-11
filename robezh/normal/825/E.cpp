#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n, m;
int in[N];
vector<int> G[N];
int res[N];

priority_queue<int> pque;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[b].push_back(a);
        in[a]++;
    }
    for(int i = 0; i < n; i++) if(in[i] == 0) pque.push(i);
    for(int i = n - 1; i >= 0; i--) {
        int x = pque.top(); pque.pop();
        res[x] = i;
        for(int nxt : G[x]) {
            in[nxt]--;
            if(in[nxt] == 0) pque.push(nxt);
        }
    }
    for(int i = 0; i < n; i++) cout << res[i] + 1 << " ";
    cout << endl;
}