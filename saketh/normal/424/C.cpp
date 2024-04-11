#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int pre[1000005];
int N, V, R;

int exp(int base, int pow){
    if(pow == 0) return 0;
    int ans = exp(base, pow/2);
    ans ^= ans;
    if(pow%2) ans ^= base;
    return ans;
}

int main(){
    pre[0] = 0;
    for(int i = 1; i<=1000000; i++)
        pre[i] = pre[i-1] ^ i;

    cin >> N;    
    for(int i=0; i<N; i++){
        cin >> V;
        R ^= V;
    }
    
    for(int c=1; c<=N; c++){
        int rem = N % c;
        int cyc = N / c;
        R ^= pre[rem] ^ exp(pre[c-1], cyc);
    }
        
    cout << R << endl;    
    return 0;
}