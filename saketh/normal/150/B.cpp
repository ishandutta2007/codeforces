#include<iostream>
using namespace std;

long long N, M, K;

int main(){
    cin >> N >> M >> K;
    if(K==1 || K > N){
        long long A = 1;
        for(int n=0; n<N; n++)
            A = (A * M) % 1000000007;
        cout << A << endl;
    }
    else if(N==K){
        long long A = 1;
        for(int n=0; n<(N+1)/2; n++)
            A = (A * M) % 1000000007;
        cout << A << endl;
    }
    else if(K%2 == 0) cout << M << endl;
    else cout << M*M << endl;
}