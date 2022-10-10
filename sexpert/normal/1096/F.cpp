#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int MAXN = 2e5 + 5;
long long BIT[MAXN];
long long n;

void add(int p, int v) {
    for(;p <= n;p += (p & -p))
        BIT[p] += v;
}

long long sum(int p) {
    long long s = 0;
    for(;p > 0;p -= (p & -p))
        s += BIT[p];
    return s;
}

long long query(int l, int r) {
    return sum(r) - sum(l - 1);
}

long long modpow(long long b, long long e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b*modpow(b, e - 1))%MOD;
    long long p = modpow(b, e/2);
    return (p*p)%MOD;
}

long long inv(long long b) {
    return modpow(b, MOD - 2);
}

int main() {
    long long dinv = 0;
    int A[MAXN];
    long long negrt[MAXN];
    long long negs = 0;
    cin >> n;
    set<int> outs;
    vector<int> in, out;
    for(int i = 1; i <= n; i++)
        outs.insert(i);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] != -1) {
            outs.erase(A[i]);
            in.push_back(A[i]);
            dinv += query(A[i] + 1, n);
            add(A[i], 1);
        }
        else
            negs++;
    }
    int ct = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(A[i] == -1)
            ct++;
        else
            negrt[A[i]] = ct;
    }
    long long minv = 0, zinv = negs*(negs - 1)/2ll;
    for(auto x : outs)
        out.push_back(x);
    for(auto x : in) {
        long long d = distance(out.begin(), lower_bound(out.begin(), out.end(), x));
        minv += negrt[x]*d;
        minv += (negs - negrt[x])*(negs - d);
    }
    if(negs == 0) {
        cout << dinv%MOD << endl;
        return 0;
    }
    //cout << dinv << " " << minv << " " << zinv << endl;
    long long p = (2*negs*dinv + 2*minv + negs*zinv)%MOD, q = (2*negs)%MOD;
    if(p == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << (p * inv(q))%MOD << endl;
}