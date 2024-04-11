#include <cstdio>
#include <string.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long N, M, K, P, g[1005][1005];
long long rs[1000005], cs[1000005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K >> P;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin >> g[i][j];
            rs[i] += g[i][j];
            cs[j] += g[i][j];
        }

    priority_queue<long long> br, bc;

    for(int i=0; i<N; i++)
        br.push(rs[i]);
  
    for(int i=0; i<M; i++)
        bc.push(cs[i]);
    
    memset(rs, 0, sizeof(rs));
    memset(cs, 0, sizeof(cs));

    for(int i=1; i<K+1; i++){
        long long r = br.top(), c = bc.top();
        
        rs[i] = rs[i-1] + r;
        cs[i] = cs[i-1] + c;

        br.pop();
        br.push(r - M * P);

        bc.pop();
        bc.push(c - N * P);
    }

    long long ans = -1LL << 50;
    for(long long i=0; i<K+1; i++)
        ans = max(ans, rs[i] + cs[K-i] - i * (K - i) * P);
    cout << ans << endl;
    return 0;
}