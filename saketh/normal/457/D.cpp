#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;

int N, M, K;
ld f[1<<17], ans;

ld lncr(int a, int b){ return f[a]-f[b]-f[a-b]; }

ld res(int r, int c){
    int v = r*c - N*r - N*c;
    if(K + v < 0) return 0;
    return exp(lncr(N, r) + lncr(N, c) + lncr(M+v, K+v) - lncr(M, K));
}

int main(){
    for(int i=1; i<1<<17; i++)
        f[i] = f[i-1] + log(i);

    cin >> N >> M >> K;
    for(int r=0; r<=N; r++)
        for(int c=0; c<=N; c++)
            ans += res(r, c);

    cout.precision(20);
    if(ans > 1e99) cout << "1e99" << endl;
    else cout << ans << endl;
    return 0;
}