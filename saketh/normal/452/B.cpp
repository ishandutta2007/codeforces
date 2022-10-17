#include <iostream>
#include <cmath>
using namespace std;

int N, M;

void p(int x, int y){
    cout << x << " " << y << endl;
}

int main(){
    cin >> N >> M;

    double diag = sqrt(N * N + M * M);
    double bles = (N < M) ? sqrt((N-1)*(N-1) + M * M)
                          : sqrt(N * N + (M-1)*(M-1));

    if(N == 0){
        p(0, 1);
        p(0, M);
        p(0, 0);
        p(0, M-1);
    }

    else if(M == 0){
        p(1, 0);
        p(N, 0);
        p(0, 0);
        p(N-1, 0);
    }

    else if(N > M) {
        if(diag + 2 * bles < 2 * diag + N){
            p(0, M);
            p(N, 0);
            p(0, 0);
            p(N, M);
        }

        else{
            p(0, 1);
            p(N, M);
            p(0, 0);
            p(N, M-1);
        }
    }

    else{
        if(diag + 2 * bles < 2 * diag + M){
            p(0, 0);
            p(N, M);
            p(N, 0);
            p(0, M);
        }
        
        else{
            p(1, 0);
            p(N, M);
            p(0, 0);
            p(N-1, M);
        }
    }
}