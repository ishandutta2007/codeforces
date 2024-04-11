#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = 1e7;
vector<int> adj[MAXN];
int ndp[MAXN][105], xdp[MAXN][105], sz[MAXN], val[MAXN], P, M;

void dfs(int s) {
    sz[s] = (val[s] == -1 ? 0 : 1);
    for(auto v : adj[s]) {
        dfs(v);
        sz[s] += sz[v];
    }
    if(P <= 100) {
        for(int pp = 0; pp <= P; pp++) {
            int mm = sz[s] - pp - 1;
            xdp[s][pp] = -INF;
            ndp[s][pp] = INF;
            if(pp >= sz[s])
                continue;
            if(sz[s] == 1) {
                ndp[s][pp] = xdp[s][pp] = val[s];
                //cout << s << " " << ndp[s][pp] << " " << xdp[s][pp] << '\n';
                continue;
            }
            if(pp) {
                for(int lp = 0; lp <= pp - 1; lp++) {
                    //cout << s << " " << adj[s][0] << " " << lp << " " << adj[s][1] << " " << pp - lp - 1 << '\n';
                    xdp[s][pp] = max(xdp[s][pp], xdp[adj[s][0]][lp] + xdp[adj[s][1]][pp - lp - 1]);
                    ndp[s][pp] = min(ndp[s][pp], ndp[adj[s][0]][lp] + ndp[adj[s][1]][pp - lp - 1]);
                }
            }
            if(mm) {
                for(int lp = 0; lp <= pp; lp++) {
                    xdp[s][pp] = max(xdp[s][pp], xdp[adj[s][0]][lp] - ndp[adj[s][1]][pp - lp]);
                    ndp[s][pp] = min(ndp[s][pp], ndp[adj[s][0]][lp] - xdp[adj[s][1]][pp - lp]);
                }
            }
        }
    }
    else {
        for(int mm = 0; mm <= M; mm++) {
            int pp = sz[s] - mm - 1;
            xdp[s][mm] = -INF;
            ndp[s][mm] = INF;
            if(mm >= sz[s])
                continue;
            if(sz[s] == 1) {
                ndp[s][mm] = xdp[s][mm] = val[s];
                //cout << s << " " << ndp[s][pp] << " " << xdp[s][pp] << '\n';
                continue;
            }
            if(pp) {
                for(int lm = 0; lm <= mm; lm++) {
                    //cout << s << " " << adj[s][0] << " " << lp << " " << adj[s][1] << " " << pp - lp - 1 << '\n';
                    xdp[s][mm] = max(xdp[s][mm], xdp[adj[s][0]][lm] + xdp[adj[s][1]][mm - lm]);
                    ndp[s][mm] = min(ndp[s][mm], ndp[adj[s][0]][lm] + ndp[adj[s][1]][mm - lm]);
                }
            }
            if(mm) {
                for(int lm = 0; lm <= mm - 1; lm++) {
                    xdp[s][mm] = max(xdp[s][mm], xdp[adj[s][0]][lm] - ndp[adj[s][1]][mm - lm - 1]);
                    ndp[s][mm] = min(ndp[s][mm], ndp[adj[s][0]][lm] - xdp[adj[s][1]][mm - lm - 1]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s >> P >> M;
    if(s.size() == 1) {
        cout << s[0] - '0' << '\n';
        return 0;
    }
    stack<int> vtx;
    int cur = 1;
    for(char c : s) {
        if(c == '?')
            continue;
        if(c == '(')  {
            val[cur] = -1;
            vtx.push(cur++);
        }
        else if(c == ')') {
            int v = vtx.top();
            vtx.pop();
            if(vtx.size()) adj[vtx.top()].push_back(v);
        }
        else {
            int v = c - '0';
            adj[vtx.top()].push_back(cur);
            val[cur++] = v;
        }
    }
    //for(int u = 1; u < cur; u++) {
    //    for(auto v : adj[u])
    //        cout << "edge " << u << " " << v << '\n';
    //}
    dfs(1);
    if(P <= 100)
        cout << xdp[1][P] << endl;
    else
        cout << xdp[1][M] << endl;
}