#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

const int N = 105;
const LL MOD = 1000000007;

int n;
int deg[N], mp[N][N];
int D[N][N], G[N][N], C[N][N]; // Matrix-Tree;

LL mpow(LL a, LL x) {
    if (x == 0)
        return 1;
    LL t = mpow(a, x>>1);
    if (x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}

LL Det_of_C(int sz) {
    /*
    printf("\n");
    for (int i=1;i<=sz;i++) {
        for (int j=1;j<=sz;j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    int a[N][N];
    for (int i = 1; i <= sz; i ++)
        for (int j = 1; j <= sz; j ++)
            a[i][j] = C[i][j];

    LL ans = 1; 

    for (int i = 1; i <= sz; i ++) {
        if (a[i][i] == 0) {
            int x = -1;
            for (int j = i+1; j <= sz; j ++) {
                if (a[j][i]) {
                    x = j; break;
                }
            }
            if (x == -1) return 0;
            for (int k = 1; k <= sz; k ++) {
                swap(a[i][k], a[x][k]);
            }
        }   

        LL k = mpow(a[i][i], MOD-2);
        for (int j = i+1; j <= sz; j ++) {

            LL t = a[j][i] * k % MOD;
            for (int k = 1; k <= sz; k ++) {
                a[j][k] -= a[i][k] * t % MOD;
                a[j][k] = ( a[j][k] % MOD + MOD ) % MOD;
            }            
        }
        if (a[i][i] == 0)
            return 0;

        ans = ans * a[i][i] % MOD;
        /*
        printf("\n");
        for (int i=1;i<=sz;i++) {
            for (int j=1;j<=sz;j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    return abs(ans);
}

LL get_Kirchhoff() {
    LL ans = Det_of_C(n-1);
    return ans;
}

LL A[N][N]; // Gauss!

void Gauss(int sz) {
    /*
    for (int i = 1; i <= sz; i ++) {
        for (int j = 1; j <= sz+1; j++) {
            printf("%lld ", A[i][j]);
        }
        printf("\n");
    }
    */
    for (int i = 1; i <= sz; i ++) {
        if (A[i][i] == 0) {
            int x = -1;
            for (int j = i+1; j <= sz; j ++) {
                if (A[j][i]) {
                    x = j; break;
                }
            }
            for (int k = 1; k <= sz; k ++) {
                swap(A[i][k], A[x][k]);
            }
        }
        LL k = mpow(A[i][i], MOD-2);
        for (int j = i+1; j <= sz; j ++) {
            LL t = A[j][i] * k % MOD;
            for (int k = 1; k <= sz+1; k ++) {
                A[j][k] -= (A[i][k] * t) % MOD;
                A[j][k] = (A[j][k] % MOD + MOD) % MOD;
            }
        }
        /*
        printf("\n");
        for (int i = 1; i <= sz; i ++) {
            for (int j = 1; j <= sz+1; j++) {
                printf("%lld ", A[i][j]);
            }
            printf("\n");
        }
        */
    }


    for (int i = sz; i >= 2; i --) {
        for (int j = i-1; j >= 1; j --) {

            int t = A[j][i] * mpow(A[i][i], MOD-2) % MOD;
            A[j][i] -= (t * A[i][i])%MOD;   
            A[j][i] = (A[j][i] % MOD + MOD) % MOD;
            
            A[j][sz+1] -= (t * A[i][sz+1])%MOD; 
            A[j][sz+1] = (A[j][sz+1] % MOD + MOD) % MOD;

        }
    }

    for (int i = 1; i <= sz; i ++) {
        A[i][sz+1] = A[i][sz+1] * mpow(A[i][i], MOD-2) % MOD;
    }
}

int main() 
{
    scanf("%d", &n);
    
    for (int i = 1; i < n; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u] ++, deg[v] ++;
        mp[u][v] = mp[v][u] = 1;
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) 
                C[i][j] = n-1;
            else
                C[i][j] = -1;
        }
    }
    
    // init line 1
    for (int i = 1; i <= n+1; i ++) {
        A[1][i] = 1;
    }
    A[1][n+1] = get_Kirchhoff();

    // init line 2 ~ n
    for (int T = 2; T <= n; T ++) {
        for (int i = 1; i <= n; i ++) {
            C[i][i] += deg[i];        
            for (int j = 1; j <= n; j ++) {
                if (mp[i][j]) C[i][j] --;
            }
        }

        for (int i = 0; i < n; i ++) {
            A[T][i+1] = mpow(T, i);
        }
        A[T][n+1] = get_Kirchhoff();
        //cout << "!" << A[T][n+1] << endl;
    }
    Gauss(n);
    for (int i = 1; i <= n; i ++) {
        printf("%lld ", A[i][n+1]);
    }
}