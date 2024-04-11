#include <bits/stdc++.h>
using namespace std;

// p           | k  | g
// 469762049     26   3
// 998244353     23   3
// 1004535809    21   3
// 2281701377    27   3

typedef long long ll;
typedef pair<int, int> P;
const int N = (1 << 22) + 50, mod = 998244353, g = 3;
const int LOGN = 23;

int rev[N], w[2][N];

int pow(int x, int k){
    int c = 1;
    for(; k; k >>= 1, x = int(x * 1LL * x % mod)) if(k & 1) c = int(c * 1LL * x % mod);
    return c;
}

void init(int len){
    for(int i = 0; i < len; i++){
        int y = 0, x = i;
        for(int k = 1; k < len; k *= 2, x >>= 1) (y <<= 1) |= (x & 1);
        rev[i] = y;
    }
    w[0][0] = w[1][0] = 1;
    int mp = pow(g, (mod-1)/len), ni = pow(mp, mod - 2);
    for(int i = 1; i < len; i++){
        w[0][i] = int(w[0][i-1] * 1LL * mp % mod);
        w[1][i] = int(w[1][i-1] * 1LL * ni % mod);
    }
}

void NTT(vector<int> &y, int on, int len){
    y.resize(len, 0);
    for(int i = 0; i < len; i++) if(i > rev[i]){int tmp = y[i]; y[i] = y[rev[i]], y[rev[i]] = tmp;}
    for(int h = 2; h <= len; h <<= 1) {
        int wi = len / h;
        for (int j = 0; j < len; j += h) {
            int l = 0;
            for (int k = j; k < j + h / 2; k++) {
                int u = y[k];
                int t = int(1LL * w[on==-1][l] * y[k + h / 2] % mod);
                y[k] = (u + t) % mod;
                y[k + h / 2] = ((u - t) % mod + mod) % mod;
                l += wi;
            }
        }
    }

    if(on == -1){
        int ni = pow(len, mod-2);
        for(int i = 0; i < len; i++) y[i] = int(1LL * y[i] * ni % mod);
    }
}

vector<int> mult_poly(vector<int> a, vector<int> b) {
    int len = 1;
    while(len < a.size() + b.size() + 1) len *= 2;
    init(len);
    NTT(a, 1, len);
    NTT(b, 1, len);
    for(int i = 0; i < len; i++) a[i] = (int)(1LL * a[i] * b[i] % mod);
    NTT(a, -1, len);
    while(!a.empty() && a.back() == 0) a.pop_back();
    return a;
}

vector<int> slice(vector<int> a, int rem) {
    vector<int> res;
    for(int i = 0; i < a.size(); i++) {
        if(i % 2 == rem) res.push_back(a[i]);
        else res.push_back(0);
    }
    return res;
}

int n;
vector<int> dp[LOGN][2][2];

void print_out(vector<int> a) {
    for(int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    cin >> n;
    int tn = n;
    dp[0][0][0] = {1};
    dp[0][0][1] = {0};
    dp[0][1][0] = {1};
    dp[0][1][1] = {0, 1};
    int pw = 1;
    for(int i = 1; i < LOGN; i++) {
        n -= pw;
        pw *= 2;
        if(n < 0) {
//            cout << "it: " << i << endl;
            int res = 0;
            if(dp[i-1][0][tn%2].size() > tn) res += dp[i-1][0][tn%2][tn];
            if(dp[i-1][1][tn%2].size() > tn) res += dp[i-1][1][tn%2][tn];
            res = (res % mod + mod) % mod;
            cout << res << '\n';
            return 0;
        }

        for(int k = 0; k < 2; k++) {
            for(int s = 0; s < 2; s++) {
                dp[i][k][s] = mult_poly(dp[i-1][!k][!k], dp[i-1][0][s^1^(!k)]);
                dp[i][k][s].insert(dp[i][k][s].begin(), 0);
//                cout << i << " " << k << " " << s << ": ";
//                print_out(dp[i][k][s]);
            }
        }

    }
}