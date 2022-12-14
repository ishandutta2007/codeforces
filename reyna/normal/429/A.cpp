#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[100000];
vector<int> taghirha;
int rafteshode[100000];
int init[100000];
int goal[100000];
int dfs(int a,int b, int v){
//  cout << a << " " << b << " " << v << endl;
    rafteshode[v] = 1;
    if(a == 0){
        init[v] = 1-init[v];
    }
    if(goal[v] != init[v]){
//      cout << "Are";
        a = 1-a;
        taghirha.push_back(v);
    }
    for(int i = 0; i < arr[v].size(); i++){
        if(rafteshode[arr[v][i]] == 0){
            dfs(b,a,arr[v][i]);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 0; i < n;i++){
        cin >> init[i];
    }
    for(int i = 0; i < n;i++){
        cin >> goal[i];
    }
    dfs(1,1,0);
    cout << taghirha.size() << endl;
    for(int i = taghirha.size()-1;i>= 0;i--){
        cout << taghirha[i]+1 << endl;
    }
}