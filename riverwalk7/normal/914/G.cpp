#include <bits/stdc++.h>
using namespace std;

const int LOG = 17;
const int K = 1 << LOG;
const int MOD = 1e9 + 7;

int mod_pow(int base, int po) {
    int ret = 1;
    while(po) {
        if(po & 1) ret = 1ll * ret * base % MOD;
        base = 1ll * base * base % MOD;
        po >>= 1;
    }
    return ret;
}

// csa xor
void fwht(vector<long long> &data, int dim) {
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                data[i + j] = (a + b) % MOD;
                data[i + j + len] = (a - b + MOD) % MOD;
            }   
        }
    }
}

// csa and
void tauk(vector<long long> &P, int dim, bool inverse) {
    for (int len = 1; 2 * len <= dim ; len <<= 1) {
        for (int i = 0; i < dim ; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                long long u = P[i + j];
                long long v = P[i + len + j];
                
                if (!inverse) {
                    P[i + j] = v % MOD;
                    P[i + len + j] = (u + v) % MOD;
                } else {
                    P[i + j] = (-u + v + MOD) % MOD;
                    P[i + len + j] = u % MOD;
                }
            }
        }
    }
}

vector<long long> xor_res(K, 0), or_res(K, 0), and_res(K, 0);
vector<long long> cnt(K, 0);
vector<int> fibo(K);

void read() {
    int n; scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
}

void process() {
    int inve = mod_pow(K, MOD-2);

    xor_res = cnt;
    fwht(xor_res, K);
    for(int i = 0 ; i < K ; i++) {
        xor_res[i] *= xor_res[i];
        xor_res[i] %= MOD;
    }
    fwht(xor_res, K);
    for(int i = 0 ; i < K ; i++) {
        xor_res[i] *= inve;
        xor_res[i] %= MOD;
    }

    and_res = cnt;
    // tauk(and_res, K, 0);
    // for(int i = 0 ; i < K ; i++) {
    //     and_res[i] *= and_res[i];
    // }
    // tauk(and_res, K, 1);

    for(int i = 1 ; i < K ; i++) {
        for(int j = i ; j >= 0 ; j = i & (j-1)) {
            int k = i - j;

            if(k > j) {
                break;
            }

            or_res[i] += cnt[j] * cnt[k] * 2;
        }
    }

    or_res[0] = cnt[0] * cnt[0];

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2 ; i < K ; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }

    for(int i = 0 ; i < K ; i++) {
        xor_res[i] %= MOD;
        or_res[i] %= MOD;
        and_res[i] %= MOD;

        xor_res[i] = xor_res[i] * fibo[i] % MOD;
        and_res[i] = and_res[i] * fibo[i] % MOD;
        or_res[i] = or_res[i] * fibo[i] % MOD;
    }

    vector<long long> res = xor_res;

    tauk(res, K, 0);
    tauk(and_res, K, 0);
    for(int i = 0 ; i < K ; i++) {
        res[i] = res[i] * and_res[i] % MOD;
    }
    tauk(res, K, 1);

    tauk(res, K, 0);
    tauk(or_res, K, 0);
    for(int i = 0 ; i < K ; i++) {
        res[i] = res[i] * or_res[i] % MOD;
    }
    tauk(res, K, 1);

    long long ret = 0;

    for(int i = 0 ; i < LOG ; i++) {
        ret = (ret + res[1 << i]) % MOD;
    }

    cout << ret << endl;
}

int main() {
    read();
    process();

    // cout << or_res[0] << " " << or_res[1] << endl;
    return 0;
}