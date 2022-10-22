#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

LL N, ans;
int M;

struct Mat{
    LL A[110][110];
    Mat operator*(const Mat &r)const{
        Mat ret;
        for (int i=1; i<=M; i++){
            for (int j=1; j<=M; j++){
                ret.A[i][j] = 0;
                for (int k=1; k<=M; k++){
                    ret.A[i][j] += A[i][k] * r.A[k][j];
                    ret.A[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
};

Mat Pow(Mat X, LL Y){
    if (Y <= 1) return X;
    Mat Z = Pow(X, Y/2);
    if (Y & 1) return Z * Z * X;
    return Z * Z;
}

int main(){
    scanf("%lld %d", &N, &M);
    if (N < M) puts("1");
    else if (N == M) puts("2");
    else{
        Mat X;
        for (int i=1; i<=M; i++) for (int j=1; j<=M; j++) X.A[i][j] = 0;
        X.A[1][1] = X.A[1][M] = 1;
        for (int i=2; i<=M; i++) X.A[i][i-1] = 1;
        X = Pow(X, N-M+1);
        for (int i=1; i<=M; i++) ans = (ans + X.A[1][i]) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}