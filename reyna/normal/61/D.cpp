#include <iostream>
#include <vector>
using namespace std;
vector<int> al[123456];
vector<int> W[123456];
int D[123456];
int V[123456];
int dfs(int i){
    if(V[i])
        return 0;
    V[i] = true;
    for(int j = 0; j < al[i].size();j++){
        int next = al[i][j];
        if(!V[next]){
            D[next] = D[i]+W[i][j];
            dfs(next);
        }
    }
}
int main(){
    int n;
    cin >> n;
    long long cnt = 0;
    for(int i = 0; i < n-1;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
        W[a].push_back(w);
        W[b].push_back(w);
        cnt+=w;
    }
    dfs(0);
    int Max = 0;
    for(int i = 0; i < n;i++){
        Max = max(Max,D[i]);
    }
    cout << cnt*2-Max << endl;
    return 0;
}