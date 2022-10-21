#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e4 + 5;
const int INF = (int)1e9;

string str;
int p,m,par = -1, s = 0;
int cnt = 0;
vector<int> G[MAXN];
int num[MAXN], S[MAXN];
int dpmin[8000][105], dpmax[8000][105];
int small, big;

void dfst(int v){
    cout << v;
    for(int nxt : G[v]) dfst(nxt);
    cout << v;
}

void dfs(int v = 0){
    if(num[v] != -1){
        dpmin[v][0] = dpmax[v][0] = num[v];
        return;
    }
    int l = G[v][0], r = G[v][1];
    dfs(l), dfs(r);
    for(int i = 0; i <= min(m,p); i++){
        for(int j = 0; j <= i-big; j++){
            dpmax[v][i] = max(dpmax[v][i], dpmax[l][j] - dpmin[r][i-big-j]);
            dpmin[v][i] = min(dpmin[v][i], dpmin[l][j] - dpmax[r][i-big-j]);
        }

        for(int j = 0; j <= i-small; j++){
            dpmax[v][i] = max(dpmax[v][i], dpmax[l][j] + dpmax[r][i-small-j]);
            dpmin[v][i] = min(dpmin[v][i], dpmin[l][j] + dpmin[r][i-small-j]);
        }
    }
}

int main(){
    fill(num, num+MAXN, -1);
    for(int i = 0; i < 8000; i++) {
        fill(dpmin[i], dpmin[i] + 105, INF);
        fill(dpmax[i], dpmax[i] + 105, -INF);
    }
    //cout <<'1';
    getline(cin, str);
    cin >> p >> m;
    small = p < m, big = p >= m;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            if(s!=0) G[S[s]].push_back(cnt);
            S[++s] = (cnt++);
        }
        else if(str[i] == ')'){
            s--;
        }
        else if(str[i] != '?'){
            G[S[s]].push_back(cnt);
            num[cnt++] = (str[i] - '0');
        }
    }

    dfs();
    cout << dpmax[0][min(m,p)];

}