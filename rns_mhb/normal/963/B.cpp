#include<bits/stdc++.h>
using namespace std;

#define N 200010

vector <int> adj[N], L, R;
bool d[N];

void dfs(int x, int p) {
    int cnt = 0;
    for(auto y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        if(d[y] == 0) cnt ++;
    }
    if(x == 1) {
        L.push_back(1);
        for(auto y : adj[x]) {
            if(y == p) continue;
            if(d[y] == 0) R.push_back(y);
        }
    }
    else {
        if(cnt & 1) {
            d[x] = 1;
            L.push_back(x);
            for(auto y : adj[x]) {
                if(y == p) continue;
                if(d[y] == 0) R.push_back(y);
            }
        }
        else {
            for(auto y : adj[x]) {
                if(y == p) continue;
                if(d[y] == 0) R.push_back(y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if(x) {
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    if(n % 2 == 0) {
        puts("NO");
        return 0;
    }
    dfs(1, 0);
    cout << "YES" << endl;
    for(int i = 0; i < L.size(); i ++) cout << L[i] << endl;
    for(int i = R.size()-1; i >= 0; i --) cout << R[i] << endl;
}