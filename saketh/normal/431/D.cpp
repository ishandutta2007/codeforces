#include <iostream>
#include <queue>
using namespace std;

long long M; int K;
long long pasc[205][205];

long long ncr(int n, int r){
    if(r < 0 || r > 200 || r > n) return 0;
    return pasc[n][r];
}

long long calc(long long X){
    long long ret = 0;
    for(int i=63, b=0; i>=0; i--)
        if((X>>i) & 1)
            ret += ncr(i, K - (b++));
    int bc = 0;
    for(long long tmp = X; tmp; tmp/=2)
        bc += tmp%2;
    if(bc == K) ret++;
    return ret;
}

int main(){
    pasc[0][0] = 1;
    for(int n=1; n<=200; n++){
        pasc[n][0] = 1;
        for(int k=1; k<=n; k++)
            pasc[n][k] = pasc[n-1][k]+pasc[n-1][k-1];
    }

    cin >> M >> K;
    
    long long low = 1, high = 1000000000000000000LL;
    while(low <= high){
        long long mid = (low + high)/2;
        long long val = calc(mid<<1) - calc(mid);
        if(val == M){
            cout << mid << endl;
            break;
        }
        else if(val > M) high = mid-1;
        else low = mid+1;
    }
    
    return 0;
}