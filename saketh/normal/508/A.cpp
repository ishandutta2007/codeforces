#include <iostream>
using namespace std;

int N, M, K;
bool grid[1005][1005];

void color(int i, int j){
    grid[i][j] = true;
}

bool check(int i, int j){
    if(i<0 || j<0) return false;
    if(i+1 == N || j+1 == M) return false;
    return grid[i][j] && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;

    for(int i=0; i<K; i++){
        int I, J;
        cin >> I >> J;
        color(I-1, J-1);

        if(check(I-2, J-2) || check(I-2, J-1) || check(I-1, J-2) || check(I-1, J-1)){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}