#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4028;

int N, M;
vector<pair<int, int>> edges;

int recog[MAXN];
bool know[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        edges.emplace_back(u-1, v-1);

        recog[u-1]++;
        recog[v-1]++;

        know[u-1][v-1] = true;
        know[v-1][u-1] = true;
    }
           
    int ans = -1;
    for (auto p : edges) {
        for (int t = 0; t < N; t++) {
            if(know[p.first][t] && know[p.second][t]) {
                int res = recog[t] + recog[p.first] + recog[p.second] - 6;
                if(ans == -1 || ans > res) ans = res;
            }
        }
    }
    
    cout << ans << endl;
}