#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 100050, N = 105;

bool p[M];
int mu[M], pm[M], pms;

int n, a[N];
map<int, int> mp;
map<int, int> f;

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
}

void factorize(int x) {
    for(int i = 0; i < pms; i++) {
        int px = pm[i];
        if(x % px == 0) {
            int cnt = 0;
            while(x % px == 0) {x /= px, cnt++;}
            mp[px] |= (1 << (cnt - 1));
        }
    }
    if(x > 1) mp[x] |= 1;
}

int get_sg(set<int> &S) {
    int cur = 0;
    for(auto x : S) {
        if(x != cur) return cur;
        else cur++;
    }
    return cur;
}

int get(int mask) {
    if(f.count(mask)) return f[mask];
    set<int> S;
    int mx_bit = -1;
    for(int b = 30; b >= 0; b--) {
        if((mask >> b) & 1) {
            mx_bit = b; break;
        }
    }
    for(int b = 0; b <= mx_bit; b++) {
        S.insert(get((((1 << b) - 1) & mask) | (mask >> (b + 1))));
//        cout << get((((1 << b) - 1) & mask) | (mask >> (b + 1))) << endl;
    }
    return f[mask] = get_sg(S);
}


int main(){
    get_mobius_and_sieve();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        factorize(a[i]);
    }
    int sg = 0;
    for(auto p : mp) {
        f.clear();
        sg ^= get(p.second);
    }
    cout << (sg ? "Mojtaba" : "Arpa") << endl;

}