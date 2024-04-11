#include <iostream>
#include <vector>
using namespace std;
int Q[3456];
int ptr1;
int ptr2;
vector<int> C;
vector<int> al[3456];
int V[3456];
int D[3456];
int P[3456];
bool k = false;
int Asli = 0;
int bfs(){
    for(int i = 0; i < C.size();i++){
        Q[ptr2] = C[i];
        V[C[i]]=true;
        ptr2++;
    //  cout << C[i] << endl;
    }
    while(ptr1 != ptr2){
        int curr = Q[ptr1];
        for(int i = 0; i < al[curr].size();i++){
            int next = al[curr][i];
            if(!V[next]){
                V[next] = true;
                Q[ptr2]=next;
                D[next] = D[curr]+1;
                ptr2++;
            }
        }
        ptr1++;
    }
}
bool l = false;
int dfs(int i){
    if(V[i]){
        k = true;
        return 0;
    }
    V[i] = true;
    for(int j = 0; j < al[i].size();j++){
        if(l == true){
            return 0;
        }
        int next = al[i][j];
        if(P[i] == next){
            continue;
        }
        if(P[next]==-1){
            P[next] = i;
            dfs(next);
        }else if(P[next]!=i){
            k = true;
            Asli = next;
        }
        if(k == true){
            if(i == Asli){
                k = false;
                l = true;
            }
    //      cout << i << endl;
            C.push_back(i);
            return 0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for(int i = 0; i < n;i++){
        P[i] = -1;
    }
    dfs(0);
    for(int i = 0; i < n;i++){
        V[i] = false;
    }
    bfs();
    for(int i = 0; i < n;i++){
        cout << D[i] << " ";
    }
    cout << endl;
    return 0;
}