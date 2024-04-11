#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 70000;

vector<int> E[6], B[4];
int sta[4][4], ta[6][2] = {{0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3}};
int n, a[N], v[N], b[N];
bool vis[4];
int ban[6], sum_e[6], sum_b[6];

void dfs(int u){
    vis[u] = true;
    for(int i = 0; i < 6; i++){
        if((ta[i][0] == u || ta[i][1] == u) && !E[i].empty()){
            int nxt = ta[i][0] == u ? ta[i][1] : ta[i][0];
            if(!vis[nxt]) dfs(nxt);
        }
    }
}

int check_dfs(){
    int res = 0;
    for(int i = 0; i < 4; i++){
        memset(vis, 0, sizeof(vis));
        dfs(i);
        int cnt = 0;
        if(vis[0]) cnt += (E[0].size() + E[1].size() + E[2].size()) % 2;
        if(vis[1]) cnt += (E[0].size() + E[3].size() + E[4].size()) % 2;
        if(vis[2]) cnt += (E[1].size() + E[3].size() + E[5].size()) % 2;
        if(vis[3]) cnt += (E[2].size() + E[4].size() + E[5].size()) % 2;
        if(cnt != 0 && cnt != 2) continue;
        int sum = 0;
        if(vis[0]) sum += (sum_e[0] + sum_e[1] + sum_e[2]);
        if(vis[1]) sum += (sum_e[0] + sum_e[3] + sum_e[4]);
        if(vis[2]) sum += (sum_e[1] + sum_e[3] + sum_e[5]);
        if(vis[3]) sum += (sum_e[2] + sum_e[4] + sum_e[5]);
        sum /= 2;
        for(int j = 0; j < 4; j++) if(vis[j]) sum += sum_b[j];
        res = max(res, sum);
    }
    return res;
}

int main(){
    sta[0][1] = 0, sta[0][2] = 1, sta[0][3] = 2, sta[1][2] = 3, sta[1][3] = 4, sta[2][3] = 5;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> v[i] >> b[i], a[i]--, b[i]--;
        if(a[i] == b[i]) B[a[i]].push_back(v[i]);
        else if(a[i] > b[i]) E[sta[b[i]][a[i]]].push_back(v[i]);
        else E[sta[a[i]][b[i]]].push_back(v[i]);
    }
    for(int i = 0; i < 6; i++) for(int x : E[i]) sum_e[i] += x;
    for(int i = 0; i < 4; i++) for(int x : B[i]) sum_b[i] += x;
    for(int i = 0; i < 6; i++) sort(E[i].begin(), E[i].end(), greater<int>());
    int res = 0;
    for(int i = 0; i < (1 << 6); i++){
        fill(ban, ban+6, -1);
        for(int j = 0; j < 6; j++){
            if(((i >> j) & 1) && !E[j].empty()){
                ban[j] = E[j].back();
                sum_e[j] -= ban[j];
                E[j].pop_back();
            }
        }
        res = max(res, check_dfs());
        for(int j = 0; j < 6; j++){
            if(ban[j] != -1){
                E[j].push_back(ban[j]);
                sum_e[j] += ban[j];
            }
        }
    }
    cout << res << endl;

}