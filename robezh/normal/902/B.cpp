#include <bits/stdc++.h>
using namespace std;

vector<int> edge[10050];
int color[10050];
bool visited[10050];
int cnt = 1;

void dfs(int now, int col){
    visited[now] = true;
    for(int i = 0; i < edge[now].size(); i++){
        int next = edge[now][i];
        if(!visited[next]){
            if(color[next] != col) cnt++;
            dfs(next, color[next]);
        }
    }
}

int main() {
    int n,a;
    fill(visited, visited+10050, 0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> a;
        edge[a].push_back(i);
        edge[i].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }
    dfs(1,color[1]);
    cout << cnt << endl;
}