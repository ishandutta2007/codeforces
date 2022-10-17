#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3e5 + 100;
const int MAXK = 5005;
const ll INF = 1e18;

int N, K;
ll val[MAXN];
ll dp[MAXK][MAXK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    sort(val, val+N);

    int F, H;
    int FS;

    if(N % K == 0) {
        FS = N / K;
        F = K;
        H = 0;
    }
    else {
        FS = N / K + 1;
        F = N % K;
        H = K - F;
    }

    for (int b = 0; b <= F; b++) {
        for (int s = 0; s <= H; s++) {
            if(b == 0 && s == 0) continue;
            dp[b][s] = INF; 
           
            int AV = b * FS + s * (FS - 1);
            if(s != 0) { // do a smaller    
                ll cost = val[AV-1] - val[AV - FS + 1];
                dp[b][s] = min(dp[b][s], dp[b][s-1] + cost); 
            }
            if(b != 0) { // do a full
                ll cost = val[AV-1] - val[AV - FS];
                dp[b][s] = min(dp[b][s], dp[b-1][s] + cost); 
            }
        }
    }

    cout << dp[F][H] << endl;
}