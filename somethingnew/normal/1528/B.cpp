#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
vector<int> a(int n){
    vector<int> md(n+1,0);
    vector<int> predmd(n+1,1);
    vector<int> p;
    long sumd = 0;
    for (int i = 0; i <= n; ++i) {
        md[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if(md[i] == i) {p.push_back(i);sumd += i;}
        for (int j = 0; j < p.size() and p[j] <= md[i] and i * 1ll * p[j] <= n; ++j) {
            md[p[j] * i] = p[j];
            sumd += p[j];
            if(p[j] == md[i]){
                predmd[p[j] * i] = predmd[i] + 1;
            }
        }
    }
    md[1] = 0;
    vector<int> sigma0(n + 1, 0);
    sigma0[1] = 1;
    long sumsigma0 = 1;
    for (int i = 2; i <= n; ++i) {
        if (md[i] != md[i / md[i]]) {
            sigma0[i] = sigma0[i / md[i]] * 2;
        } else {
            sigma0[i] = sigma0[i / md[i]] / predmd[i] * (predmd[i] + 1);
        }
        sumsigma0 += sigma0[i];
    }
    return sigma0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> sigma0 = a(n);
    int sum = 2;
    for (int i = 2; i <= n; ++i) {
        int d = sigma0[i] - 1;
        if (i == n) {
            cout << (sum + d) % 998244353;
            return 0;
        }
        sum *= 2;
        sum += d;
        sum %= 998244353;
    }
}