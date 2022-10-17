#include <iostream>
using namespace std;

int N, M;
int R1, C1;
int R2, C2;
char g[505][505];

int P[500005];
int R[500005];
int S[500005];

void init(int N){
    for(int i=0; i<N; i++){
        P[i] = i;
        R[i] = 0;
        S[i] = 1;
    }
}

int rep(int i){
    if(P[i] != i) P[i] = rep(P[i]);
    return P[i];
}

bool unio(int a, int b){
    a = rep(a);
    b = rep(b);
    if(a == b) return false;
    if(R[a] < R[b]){
        P[a] = b;
        S[b] += S[a];
    }
    else{
        P[b] = a;
        S[a] += S[b];
    }
    if(R[a] == R[b]) R[a]++;
    return true;
}

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool safe(int i, int j){
    if(i<0 || j<0) return false;
    if(i>=N || j>=M) return false;
    if(i==R1 && j==C1) return true;
    if(i==R2 && j==C2) return true;
    return g[i][j] != 'X'; 
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> g[i][j];

    cin >> R1 >> C1;
    cin >> R2 >> C2;
    R1--, C1--, R2--, C2--;

    int can = 0;
    for(int d=0; d<4; d++)
        can += safe(R2 + dir[d][0], C2 + dir[d][1]);

    init(500 * 500);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(!safe(i, j)) continue;
            for(int d=0; d<4; d++){
                if(!safe(i + dir[d][0], j + dir[d][1])) continue;
                unio(500 * i + j, 500 * (i + dir[d][0]) + j + dir[d][1]);    
            }
        }

    bool ok = can >= 2 || (can >= 1 && g[R2][C2] == 'X');
    if(!ok || rep(500 * R1 + C1) != rep(500 * R2 + C2)) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
}