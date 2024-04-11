#include<iostream>
using namespace std;

int N, M, P, B;
int *vals[20];

int main(){
    cin >> N >> M;
    int a = 1 << N;
    
    vals[0] = new int[a];
    for(int c=0; c<a; c++)
        cin >> vals[0][c];
        
    for(int n=1; n<=N; n++){
        int len = 1 << (N-n);
        vals[n] = new int[len];
        
        for(int c=0; c<len; c++){
            if(n%2 == 1)
                vals[n][c] = vals[n-1][2*c] | vals[n-1][2*c+1];
            else
                vals[n][c] = vals[n-1][2*c] ^ vals[n-1][2*c+1];
        }
    }
    
    for(int m=0; m<M; m++){
        cin >> P >> B; 
        vals[0][--P] = B;
        
        for(int n=1; n<=N; n++){
            P/=2;
            if(n%2 == 1)
                vals[n][P] = vals[n-1][2*P] | vals[n-1][2*P+1];
            else
                vals[n][P] = vals[n-1][2*P] ^ vals[n-1][2*P+1];
        }
        
        cout << vals[N][0] << endl;
    }
    
    return 0;
}