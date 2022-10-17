#include <iostream>
using namespace std;

const int MAXN = 32;
const int MAXK = 256;

double dp[MAXN][MAXN][MAXK];

int N, K;
int v[MAXN];

int apply(int i, int l, int r){
    if(l > r) swap(l, r);
    if(i < l || i > r) return i;
    return l + r - i;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> v[i];

    for(int a=1; a<=min(K, 100); a++){
        for(int l=0; l<N; l++){
            for(int r=l; r<N; r++){
                double ch = 1.0 / (N*(N-1)/2 + N);
                for(int i=0; i<N; i++)
                    for(int j=i+1; j<N; j++){
                        int ii = apply(i, l, r);
                        int jj = apply(j, l, r);

                        if(ii < jj) 
                            dp[i][j][a] += ch * dp[ii][jj][a-1];
                        else
                            dp[i][j][a] += ch * (1 - dp[jj][ii][a-1]);
                    }
            }
        }
    }

    double res = 0;
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
            if(v[i] < v[j])
                res += dp[i][j][K];
            else res += 1 - dp[i][j][K];
    
    cout.precision(20);
    cout << res << endl;
}