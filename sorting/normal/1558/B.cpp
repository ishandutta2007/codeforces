#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
const int N = 4e6 + 3;

int n, m;
int dp[N], big[N];

vector<int> get_primes(int x){
    vector<int> ret;
    while(x != 1){
        ret.push_back(big[x]);
        x /= big[x];
    }
    return ret;
}

void recurse(const vector<int> &p, vector<int> &ret, int x, int idx){
    if(idx == p.size()){
        ret.push_back(x);
        return;
    }
    recurse(p, ret, x * p[idx], idx + 1);
    int nxt = idx + 1;
    while(nxt != p.size() && p[idx] == p[nxt])
        ++nxt;
    recurse(p, ret, x, nxt);
}

vector<int> get_divisors(int x){
    vector<int> p = get_primes(x);
    vector<int> ret;
    recurse(p, ret, 1, 0);
    return ret;
}

inline void fix(int &x){
    x = (x >= m) ? (x - m) : x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 2; i <= n; ++i)
        if(!big[i])
            for(int j = i; j <= n; j += i)
                big[j] = i;

    dp[1] = 1;
    int sum = 1, oth = 0;
    for(int i = 2; i <= n; ++i){
        dp[i] = sum;
        vector<int> v = get_divisors(i);
        for(int d: v){
            if(d == 1) continue;
            oth -= dp[i / d - 1];
            oth += dp[i / d];
            if(oth < 0) oth += m;
            if(oth >= m) oth -= m;
        }
        dp[i] += oth;
        fix(dp[i]);
        sum += dp[i];
        fix(sum);
    }
    cout << dp[n] << "\n";
}