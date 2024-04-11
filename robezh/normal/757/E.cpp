#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1000050, N = M, mod = (int)1e9 + 7;

int p[M];
int mu[M], pm[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
//    fill(p, p + M, true);
    for(int i = 1; i < M; i++) p[i] = i;
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i] == i){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = pm[j];
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int T;
ll pw[N][20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    get_mobius_and_sieve();
    for(int r = 0; r < N; r++) {
        pw[r][0] = 1;
        if(r == 0) fill(pw[r], pw[r] + N, 2);
        else for (int j = 1; j < 20; j++) pw[r][j] = (pw[r][j - 1] + (r == 0 ? 0 : pw[r - 1][j])) % mod;
    }
    cin >> T;
    while(T--) {
        int r, n;
        ll res = 1;
        cin >> r >> n;
        while(n > 1) {
            int cnt = 0;
            int cur_p = p[n];
            while(n % cur_p == 0) n /= cur_p, cnt++;
//            cout << ": " << pw[cnt][r] << endl;
            res = (res * pw[r][cnt]) % mod;
        }
        cout << res << "\n";

    }


}