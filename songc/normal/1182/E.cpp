#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 2147483647
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL N, A, B, C, K, ans=1;

struct Mat{
    int sz;
    LL m[5][5];

    Mat(){for (int i=0; i<5; i++) for (int j=0; j<5; j++) m[i][j]=0;}

    Mat operator*(const Mat &r)const{
        Mat ret;
        ret.sz = sz;
        for (int i=0; i<sz; i++) for (int j=0; j<sz; j++){
            for (int k=0; k<sz; k++) ret.m[i][j] = (ret.m[i][j] + m[i][k] * r.m[k][j]) % (MOD-1);
        }
        return ret;
    }
};

Mat MatPow(Mat X, LL Y){
    if (Y == 1) return X;
    Mat Z = MatPow(X, Y/2);
    if (Y & 1) return Z * Z * X;
    return Z * Z;
}

LL Pow(LL X, LL Y){
    if (Y == 1) return X;
    LL Z = Pow(X, Y/2);
    if (Y & 1) return Z * Z % MOD * X % MOD;
    return Z * Z % MOD;
}

int main(){
    scanf("%lld %lld %lld %lld %lld", &N, &A, &B, &C, &K);
    Mat t;
    t.sz = 3;
    t.m[0][0] = t.m[0][1] = t.m[0][2] = t.m[1][0] = t.m[2][1] = 1;
    t = MatPow(t, N-1);
    ans = (ans * Pow(A, t.m[2][2])) % MOD;
    ans = (ans * Pow(B, t.m[2][1])) % MOD;
    ans = (ans * Pow(C, t.m[2][0])) % MOD;
    Mat k;
    k.sz = 5;
    k.m[0][0] = k.m[0][1] = k.m[0][2] = k.m[0][3] = k.m[0][4] = 1;
    k.m[1][0] = k.m[2][1] = k.m[3][3] = k.m[3][4] = k.m[4][4] = 1;
    k = MatPow(k, N-3);
    ans = (ans * Pow(K, 2*k.m[0][4])) % MOD;
    printf("%lld", ans);
    return 0;
}