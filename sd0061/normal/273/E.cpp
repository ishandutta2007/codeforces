#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;

int n , p;
int L[N] , R[N];
int f[N] , cnt;
LL F[N][4];
pair<int , int> get(LL x) {
    int i = lower_bound(R , R + cnt , x / 3) - R;
    int j = lower_bound(R , R + cnt , x - x / 3) - R;
    return make_pair(i , j);
}
int mex(int i , int j) {
    if (i > j) swap(i , j);
    if (i != 0)
        return 0;
    else if (j != 1)
        return 1;
    else
        return 2;
}

void work() {
    cin >> n >> p;
    cnt = 1;
    f[0] = 0 , L[0] = 1 , R[0] = 2;
    LL x = 3;
    while (x <= p) {
        pair<int , int> tmp = get(x);
        LL l = x , r = p + 1 , m;
        while (l < r) {
            m = l + r >> 1;
            if (get(m) != tmp)
                r = m;
            else
                l = m + 1;
        }
        f[cnt] = mex(f[tmp.first] , f[tmp.second]);
        if (f[cnt] == f[cnt - 1]) {
            R[cnt - 1] = l - 1;
        } else {
            L[cnt] = x , R[cnt] = l - 1;        
            cnt ++;
        }
        x = l;
    }
    LL s[3] = {};
    for (int i = 0 ; i < cnt ; ++ i) {
        LL l = L[i] , r = R[i];
        s[f[i]] += (LL)(R[i] - L[i] + 1) * p % Q;
        s[f[i]] -= (LL)(R[i] - L[i] + 1) * (L[i] + R[i]) % Q * ((Q + 1) / 2) % Q;
        s[f[i]] += Q , s[f[i]] %= Q;
    }
    F[0][0] = 1;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < 4 ; ++ j) {
            for (int k = 0 ; k < 3 ; ++ k) {
                F[i + 1][j ^ k] += F[i][j] * s[k] % Q;
                F[i + 1][j ^ k] %= Q;
            }
        }
    }
    cout << (F[n][1] + F[n][2] + F[n][3]) % Q << endl;   
}

int main() {
    work();
    return 0;
}