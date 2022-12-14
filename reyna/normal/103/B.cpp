#include <iostream>
#include <vector>
using namespace std;
vector<int> al[101];
int cnt = 0;
bool V[101];
void dfs(int i){
    if(V[i])
        return;
    V[i] = true;
    cnt++;
    for(int j = 0; j < al[i].size();j++){
        int next = al[i][j];
        dfs(next);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    if(n != m){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    dfs(0);
    if(cnt != n){
        cout << "NO" << endl;
        return 0;
    }
    cout << "FHTAGN!" << endl;
    return 0;
}