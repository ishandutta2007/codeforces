#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int Q = 1e9 + 7;

int n , m , len[N], digit[N], deg[N];
vector<pair<int, int>> e[N];

int u[N][10], cnt , id[N];
int f[19][N] , dep[N];
int res[N];

void newnode(int &x , int fa) {
    x = ++ cnt;
    f[0][x] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 1 ; i < 19 ; ++ i) {
        f[i][x] = f[i - 1][f[i - 1][x]];
    }
}

// return true if node[x] < node[y]
bool cmp(int x , int y) {
    assert(dep[x] == dep[y]);
    for (int i = 18 ; i >= 0 ; -- i) {
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    }
    int z = f[0][x] , rx , ry;
    for (int i = 0 ; i < 10 ; ++ i) {
        if (u[z][i] == x) {
            rx = i;
        } 
        if (u[z][i] == y) {
            ry = i;
        }
    }
    return rx < ry;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].emplace_back(y , i + 1);
        e[y].emplace_back(x , i + 1);
    }
    for (int i = 1 ; i <= m ; ++ i) {
        digit[i] = digit[i / 10] + 1;
    }

    priority_queue<pair<int, int>> q;
    memset(len , 0x3f , sizeof(len));
    len[1] = 0;
    q.push({0, 1});
    vector<int> seq;
    for (int x , w ; !q.empty() ;) {
        tie(w , x) = q.top();
        q.pop();
        if (-w > len[x]) {
            continue;
        }
        seq.emplace_back(x);
        for (auto &it : e[x]) {
            int y = it.first;
            int z = it.second;
            if (len[x] + digit[z] < len[y]) {
                len[y] = len[x] + digit[z];
                q.push({-len[y] , y});
            }
        }
    }

    cnt = 1;
    id[1] = 1;

    for (auto x : seq) {
        for (auto &it : e[x]) {
            int y = it.first;
            int z = it.second;
            if (len[x] + digit[z] != len[y]) {
                continue;
            }

            int node = id[x];
            int tmp = res[x];
            for (auto ch : to_string(z)) {
                int c = ch - '0';
                if (!u[node][c]) {
                    newnode(u[node][c], node);
                }
                tmp = (10LL * tmp + c) % Q;
                node = u[node][c];
            }

            if (!id[y] || cmp(node, id[y])) {
                id[y] = node;
                res[y] = tmp;
            }
        }
    }

    for (int i = 2 ; i <= n ; ++ i) {
        printf("%d\n" , res[i]);
    }
}