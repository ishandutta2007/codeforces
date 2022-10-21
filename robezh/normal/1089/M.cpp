#include <bits/stdc++.h>
using namespace std;

string str[18][55];
// TODO: Change h back!

int h = 17, a = 50, b = 50;
//int h = 9, a = 15, b = 15;
int n = 0;
int to[10][10];
int scnt = 0;
vector<int> scc[10];
int in[10];
int nto[10][10];
int in_deg[10], topo[10];
queue<int> que;
int sz = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

//    int m;
//    cin >> m;
//    for(int i = 0; i < m; i++) {
//        int a, b; cin >> a >> b; a--, b--;
//        to[a][b] = 1;
//    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> to[i][j];
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) to[i][j] |= (to[i][k] && to[k][j]);
        }
    }
    memset(in, -1, sizeof(in));
    for(int i = 0; i < n; i++) {
        if(in[i] == -1) {
            scc[scnt].push_back(i);
            in[i] = scnt;
            for(int j = i + 1; j < n; j++) {
                if(in[j] == -1 && to[i][j] && to[j][i]) {
                    scc[scnt].push_back(j);
                    in[j] = scnt;
                }
            }
            scnt++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) nto[in[i]][in[j]] |= to[i][j];
    }


    for(int i = 0; i < scnt; i++) {
        for(int j = 0; j < scnt; j++){
            if(i != j && nto[i][j]) in_deg[j]++;
        }
    }

    for(int i = 0; i < scnt; i++) {
        if(in_deg[i] == 0) {
            que.push(i);
        }
    }
    sz = 0;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        topo[sz++] = v;
        for(int j = 0; j < scnt; j++) {
            if(nto[v][j]) {
                in_deg[j]--;
                if(in_deg[j] == 0) que.push(j);
            }
        }
    }
//    for(int i = 0; i < h; i++) {
//        for(int j = 0; j < a; j++) {
//            cout << str[i][j].length() << '\n';
//        }
//        cout << '\n';
//    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < a; j++) {
            for(int k = 0; k < b; k++) {
                str[i][j].push_back((i % 2 == 0 ? '.' : '#'));
            }
        }
    }
//    for(int i = 0; i < h; i++) {
//        for(int j = 0; j < a; j++) {
//            cout << str[i][j].length() << '\n';
//        }
//        cout << '\n';
//    }

    for(int x = 0; x < scnt; x++) {
        int i = topo[x];
        int ly = x * 2;
        for(int j = 0; j < scc[i].size(); j++) {
            str[ly][0][j] = (char)('1' + scc[i][j]);
        }
    }
    int cur = 0;
    for(int i = 0; i < scnt; i++) {
        for(int j = 0; j < scnt; j++) {
            if(i != j && nto[topo[i]][topo[j]]) {
                // Check for loop
                for(int k = i * 2 + 1; k < j * 2; k++) {
                    int x = cur / 9, y = cur % 9;
                    int cx = x * 5 + 3, cy = y * 5 + 2;
                    for(int dx = -1; dx <= 1; dx++) {
                        for(int dy = -1; dy <= 1; dy++) {
                            if(dx == 0 && dy == 0) str[k][cx + dx][cy + dy] = '.';
                            else str[k][cx + dx][cy + dy] = '#';
                        }
                    }
                }
                cur++;
            }
        }
    }
    cout << a << " " << b << " " << h << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < a; j++) {
            cout << str[i][j] << '\n';
        }
        cout << '\n';
    }


}