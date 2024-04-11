#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 30005;

int N, T, W;
vector<int> adj[MAXN];
bool go[MAXN];
queue<int> bfs;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> T; T--;
    for(int i=0; i<N-1; i++){
        cin >> W;
        adj[i].push_back(i+W);
    }

    bfs.push(0);
    while(!bfs.empty()){
        int loc = bfs.front();
        bfs.pop();
        for(int oth : adj[loc]){
            if(go[oth]) continue;
            go[oth] = true;
            bfs.push(oth);
        }
    }

    cout << (go[T]?"YES":"NO") << endl;
    return 0;
}