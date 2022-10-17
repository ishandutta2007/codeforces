#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 5005;

int N, T, ch[MAXN];
double pr[MAXN];
double dp[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> T;
    for(int i=0; i<N; i++){
        cin >> pr[i] >> ch[i];
        pr[i] /= 100;
    }

    for(int s = N-1; s>=0; s--){
        double sf = 0;
        double pw = pow(1-pr[s], ch[s]);

        for(int t = 1; t<=T; t++){
            sf *= (1 - pr[s]);
            if(t > ch[s])
                sf -= pw * pr[s] * (1 + dp[s+1][t-ch[s]-1]);
            
            sf += pr[s] * (1 + dp[s+1][t-1]);
            dp[s][t] = sf;
            if(t >= ch[s]) dp[s][t] += pw * (1 + dp[s+1][t-ch[s]]);
        }
    }

    cout.precision(20);
    cout << dp[0][T] << endl;
    return 0;
}