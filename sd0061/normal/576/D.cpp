#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
typedef long long LL;
const int N = 155;
int n , m;
struct Matrix {
    int n , m;
    bitset<N> a[N];
    Matrix (int _n = 0 , int _m = 0) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
    bitset<N>& operator [] (int x) {
        return a[x];
    }
    const bitset<N>& operator [] (int x) const {
        return a[x];
    }
};
Matrix operator * (const Matrix& A , const Matrix& B) {
    Matrix res(A.n , B.m);
	for(int i = 0; i < A.n; ++ i) {
		for(int j = 0; j < A.m; ++ j) {
			if (A[i][j]) {
				res[i] |= B[j];
			}
		}
    }
	return res;
}
struct edge {
    int x , y , t;
    bool operator < (const edge& R) const {
        return t < R.t;
    }
}e[N];
int T[N] , D;
Matrix F[N] , g[N][30] , G;
int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d" , &e[i].x, &e[i].y , &e[i].t);
        -- e[i].x , -- e[i].y;
        T[D ++] = e[i].t;
    }
    e[m ++] = (edge) {n - 1 , n - 1, 0};
    T[D ++] = 0;
    sort(T , T + D);
    D = unique(T , T + D) - T;
    sort(e , e + m);

    F[0].n = 1 , F[0].m = n , F[0][0][0] = 1;
    G.n = G.m = n;
    for (int i = 0 , j = 0 ; i < D ; ++ i) {
        while (j < m && e[j].t == T[i]) {
            G[e[j].x][e[j].y] = 1;
            ++ j;
        }
        g[i][0] = G;
        for (int k = 1 ; k < 30 ; ++ k)
            g[i][k] = g[i][k - 1] * g[i][k - 1];
        if (i + 1 < D) {
            F[i + 1] = F[i];
            int K = T[i + 1] - T[i];
            for (int k = 0 ; k < 30 && K ; ++ k)
                if (K >> k & 1) {
                    K ^= (1 << k);
                    F[i + 1] = F[i + 1] * g[i][k];
                }
        }
    }
    int l = 0 , r = 1e9 + 200 , v;
    while (l < r) {
        int v = l + r >> 1;
        int j = upper_bound(T , T + D , v) - T - 1;
        Matrix f = F[j];
        int K = v - T[j];
        for (int k = 0 ; k < 30 && K ; ++ k)
            if (K >> k & 1) {
                K ^= (1 << k);
                f = f * g[j][k];
            }
        if (f[0][n - 1])
            r = v;
        else
            l = v + 1;
    }
    if (r == 1000000200)
        puts("Impossible");
    else
        printf("%d\n" , r);
    return 0;
}