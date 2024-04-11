#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector <int> adj[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while(m --) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back((y-x+n)%n);
        adj[y].push_back((x-y+n)%n);
    }
    for(int i = 1; i <= n; i ++) sort(adj[i].begin(), adj[i].end());
    for(int d = 1; d < n; d ++) if(n % d == 0) {
        bool flag = 1;
        for(int j = d + 1; j <= n; j ++) {
            if(adj[j].size() != adj[j-d].size()) {flag = 0; break;}
            for(int k = 0; k < adj[j].size(); k ++) if(adj[j][k] != adj[j-d][k]) {flag = 0; break;}
            if(!flag) break;
        }
        if(flag) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}