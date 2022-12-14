#include <iostream>
using namespace std;
int n,m;
bool V[21];
bool H[21];
bool Visit[21][21];
int counter;
int dfs(int i, int j){
    if(Visit[i][j] == true || i == -1 || i == n || j == -1 || j == m){
        return 0;
    }
    Visit[i][j] = true;
    if(H[j] == 1){
        for(int l = i+1; l < n;l++){
            dfs(l,j);
        }
    }else{
        for(int l = 0; l < i;l++){
            dfs(l,j);
        }
    }
    if(V[i] == 1){
        for(int r = j+1; r < m;r++){
            dfs(i,r);
        }
    }else{
        for(int r = 0; r < j;r++){
            dfs(i,r);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        char a;
        cin >> a;
        if(a == '>'){
            V[i] = 1;
        }
    }
    for(int i = 0; i < m;i++){
        char a;
        cin >> a;
        if(a == 'v'){
            H[i] = 1;
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            dfs(i,j);
            for(int r = 0; r < n;r++){
                for(int l = 0; l < m;l++){
                    if(Visit[r][l]==false){
                        cout << "NO"<< endl;
                        return 0;
                    }
                    Visit[r][l] = false;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}