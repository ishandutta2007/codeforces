#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n , m , a[N] , Q[2];
int fac[N];
int cnt[N];
int C[N] , h[N] , I[2][N];

bool isprime(int x) {
    for (int i = 2 ; i * i <= x ; ++ i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

bool check(int val) {
    for (int j = 0 ; j < 2 ; ++ j) {
        int QQ = Q[j];
        for (int i = 0 ; i < val ; ++ i) {
            C[i] = 0;
        }
        int x = 1;
        for (int i = val ; i <= n ; ++ i) {
            C[i] = x;
            x = 1LL * x * (i + 1) % QQ * I[j][i - val + 1] % QQ;
        }
        for (int i = N - 1 ; i > 0 ; -- i) {
            h[i] = C[cnt[i]];
            for (int k = i + i ; k <= N ; k += i) {
                h[i] += QQ - h[k];
                if (h[i] >= QQ) {
                    h[i] -= QQ;
                }
            }
        }
        if (h[1]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0));
    scanf("%d" , &m);
    int gcd = 0;
    set<int> h;

    for (int i = 2 ; i < N ; ++ i) {
        if (!fac[i]) {
            for (int j = i ; j < N ; j += i) {
                if (!fac[j]) {
                    fac[j] = i;
                }
            }
        }
    }

    for (int i = 0 ; i < m ; ++ i) {
        int x;
        scanf("%d" , &x);
        int y = 1;
        while (x > 1) {
            int z = fac[x];
            while (x % z == 0) {
                x /= z;
            }
            y *= z;
        }
        h.insert(y);
    }

    for (auto it : h) {
        a[n ++] = it;
        gcd = __gcd(it , gcd);
        ++ cnt[it];
        //cout << it << endl;
    }

    if (gcd > 1) {
        puts("-1");
        return 0;
    }

    for (int i = 1 ; i < N ; ++ i) {
        for (int j = i + i ; j < N ; j += i) {
            cnt[i] += cnt[j];
        }
    }

    Q[0] = rand() % (int) 6e7 + (int)1e9;
    Q[1] = Q[0] + 1;

    while (!isprime(Q[0])) -- Q[0];
    while (!isprime(Q[1])) ++ Q[1];
    //cout << Q[0] << ' ' << Q[1] << endl;

    for (int j = 0 ; j < 2 ; ++ j) {
        int QQ = Q[j];
        I[j][0] = I[j][1] = 1;
        for (int i = 2 ; i <= n ; ++ i) {
            I[j][i] = 1LL * (QQ - QQ / i) * I[j][QQ % i] % QQ;
        }
    }

    int l = 1 , r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n" , r);
}