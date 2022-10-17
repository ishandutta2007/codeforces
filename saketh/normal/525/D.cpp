#include <iostream>
using namespace std;

int N, M;
char grid[2048][2048];

void go(int i, int j){
    if(i<0 || j<0) return;
    if(i >= N-1) return;
    if(j >= M-1) return;

    int c = 0;
    for(int x=0; x<4; x++)
        c += grid[i+x/2][j+x%2] == '*';

    if(c == 1){
        for(int x=0; x<4; x++)
            grid[i+x/2][j+x%2] = '.';
       

        for(int di=-1; di<=1; di++)
            for(int dj=-1; dj<=1; dj++)
                go(i+di, j+dj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> grid[i][j];

    for(int i=0; i<N; i++)
       for(int j=0; j<M; j++)
          go(i, j); 

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << grid[i][j];
        cout << "\n";
    }

    cout.flush();
}