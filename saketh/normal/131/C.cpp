#include<iostream>
using namespace std;

int N, M, T;
long long A;
long long binom[32][32];

int main(){
    cin >> N >> M >> T;
    A = 0;
    
    binom[0][0] = 1;
    for(int a=1; a<=30; a++){
        binom[a][0] = 1;
        for(int b=1; b<a; b++)
            binom[a][b] = binom[a-1][b-1] + binom[a-1][b];
        binom[a][a] = 1;
    }
    
    for(int b=max(4,T-M); b<T && b<=N; b++)
        A += binom[N][b] * binom[M][T-b];
    cout << A << endl;
}