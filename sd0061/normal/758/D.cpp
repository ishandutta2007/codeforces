#include <bits/stdc++.h>
using namespace std;

const int N = 70;

int n , m;
char str[N];

int num[N][N];
long long f[N][N] , inf = 1e18 , power[N];



int main() {
    cin >> n >> str;
    m = strlen(str);
    for (int i = 0 ; i < m ; ++ i) {
        for (int j = i ; j < m ; ++ j) {
            num[i][j] = min((long long)n , num[i][j - 1] * 10LL + str[j] - '0');
        }
    }
    memset(f , 0x3f , sizeof(f));
    f[m][0] = 0;
    power[0] = 1;
    for (int i = 1 ; i <= m ; ++ i) {
        if (power[i - 1] > inf / n) {
            power[i] = inf + 1;
        } else {
            power[i] = power[i - 1] * n;
        }
    }

    for (int i = m ; i > 0 ; -- i) {
        for (int j = 0 ; j <= m ; ++ j) {
            if (f[i][j] > inf) continue;
            for (int k = i - 1 ; k >= 0 ; -- k) {
                if (num[k][i - 1] >= n) break;
                if (k + 1 < i && str[k] == '0') continue;
                if (num[k][i - 1] > inf / power[j]) continue;
                f[k][j + 1] = min(f[k][j + 1] , f[i][j] + power[j] * num[k][i - 1]);
            }
        }
    }
    long long res = inf;
    for (int i = 0 ; i <= m ; ++ i) {
        res = min(res , f[0][i]);
    }
    cout << res << endl;
}