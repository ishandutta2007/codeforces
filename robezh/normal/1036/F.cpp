#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = (int)1e5 + 50, M = 65;
const double EPS = 1e-6;

int n;
P num[N];
ll res[N];
bool p[M];
int mu[M], pm[M], pms;

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }

        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
    //for(int i = 1; i <= 60; i++) cout << i << ": " << mu[i] << " " << endl;
}

ll fp(ll x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 == 0 ? hf * hf : hf * hf * x;
}

ll solve(ll x){
    ll res = 0;
    for(int i = 1; i <= 60; i++){
        if(mu[i] != 0){
            ll cur = (powl(x, 1.0/i)) - 0.5;
            cur += (powl(cur+1, i) - EPS <= x);
            res += mu[i] * (cur - 1);
        }
    }
    return res;
}



int main(){
    get_mobius_and_sieve();

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &num[i].first);
        num[i].second = i;
    }
    //sort(num, num + n);
    for(int i = 0; i < n; i++){
        printf("%I64d\n", solve(num[i].first));
    }

}