#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;

int N, M;
char g[3005][3005];
ll w[3005][3005];

void calc(){
    w[0][0] = 1LL;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(i==0 && j==0) continue;
            w[i][j] = 0;
            if(g[i][j]!='.') continue;
            if(i) w[i][j] = (w[i][j] + w[i-1][j]) % MOD;
            if(j) w[i][j] = (w[i][j] + w[i][j-1]) % MOD;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> g[i][j];

    g[0][1]++;
    calc();
    ll dc = w[N-1][M-2], dw = w[N-2][M-1];

    g[0][1]--, g[1][0]++;
    calc();
    ll rc = w[N-2][M-1], rw = w[N-1][M-2];

    ll res = (dc * rc - dw * rw) % MOD;
    if(res < 0) res += MOD;
    cout << res << endl;
}