#include <iostream>
using namespace std;

long long N, M, K;

long long smaller(long long X){
    long long ct = 0;
    for(int i=1; i<=N; i++)
        ct += min(X-1, M*i)/i;
    return ct;
}

int main(){
    cin >> N >> M >> K;

    long long lo = 1, hi = N * M;

    while(true){
        long long mi = (lo + hi)/2;
    
        long long s1 = smaller(mi);
        long long s2 = smaller(mi+1);

        if(s1 >= K) hi = mi - 1;
        else if(s2 < K) lo = mi + 1;
        else{
            cout << mi << endl;
            return 0;
        }
    }

    return 0;
}