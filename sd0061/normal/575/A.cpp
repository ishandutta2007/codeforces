#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 50005;
int Q;
int n , m , s[N];
LL K;
pair<LL , int> update[N];
struct Matrix {
    int n , m;
    int a[2][2];
    Matrix (int _n = 0 , int _m = 0) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
    int* operator [] (int x) {
        return a[x];
    }
    const int* operator [] (int x) const {
        return a[x];
    }
};
Matrix operator * (const Matrix& A , const Matrix& B) {
    Matrix res(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k) {
                res[i][k] += (LL)A[i][j] * B[j][k] % Q;
                if (res[i][k] >= Q)
                    res[i][k] -= Q;
            }
    return res;
}
int getS(LL x) {
    auto p = lower_bound(update , update + m , make_pair(x , 0));
    if (p -> first == x)
        return p -> second;
    return s[x % n];
}
Matrix f[16][N] , ALL;
Matrix getmatrix(int l , int r) {
    Matrix res(2 , 2);
    res[0][0] = res[1][1] = 1;
    r = r - l + 1;
    for (int i = 0 ; r ; ++ i) {
        if (r & 1) {
            res = res * f[i][l];
            l += 1 << i;
        }
        r >>= 1;
    }
    return res;
}
Matrix range(LL l , LL r) {
    Matrix res(2 , 2);
    res[0][0] = res[1][1] = 1;
    LL i = l / n , j = r / n , L = l % n , R = r % n;
    if (i == j)
        return getmatrix(L , R);
    res = getmatrix(L , n - 1);
    LL p = j - i - 1;
    Matrix A = ALL;
    while (p) {
        if (p & 1)
            res = res * A;
        A = A * A , p >>= 1;
    }
    res = res * getmatrix(0 , R);
    return res;
}
void work() {
    scanf("%lld%d%d" , &K , &Q , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &s[i]);
        s[i] %= Q;
    }
    for (int i = 0 ; i < n ; ++ i) {
        Matrix &A = f[0][i];
        A.n = A.m = 2;
        A[0][0] = 0 , A[0][1] = s[i];
        A[1][0] = 1 , A[1][1] = s[(i + 1) % n];
    }
    for (int j = 1 ; 1 << j <= n ; ++ j) {
        for (int i = 0 ; i + (1 << j) - 1 < n; ++ i)
            f[j][i] = f[j - 1][i] * f[j - 1][i + (1 << j - 1)];
    }
    ALL = getmatrix(0 , n - 1);
    scanf("%d" , &m);
    vector<LL> V;
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%lld%d" , &update[i].first , &update[i].second);
        update[i].second %= Q;
        V.push_back(update[i].first);
        if (update[i].first)
            V.push_back(update[i].first - 1);
    }
    sort(update , update + m);
    V.push_back(K);
    sort(V.begin() , V.end());
    V.erase(unique(V.begin() , V.end()) , V.end());
    while (!V.empty() && V.back() > K)
        V.pop_back();
    Matrix res(1 , 2);
    res[0][0] = 0 , res[0][1] = 1;
    LL x = -1;
    for (int i = 0 ; i < V.size() ; ++ i) {
        LL y = V[i];
        if (x + 1 <= y - 1)
            res = res * range(x + 1 , y - 1);
        if (y == K) {
            printf("%d\n" , res[0][0]);
            return;
        }
        Matrix P(2 , 2);
        P[1][0] = 1 , P[0][1] = getS(y) , P[1][1] = getS(y + 1);
        res = res * P;
        x = y;
    }
}

int main() {
    work();
    return 0;
}
/*
10 8
3
1 2 1
2
7 3
5 4
*/