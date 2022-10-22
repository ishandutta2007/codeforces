#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1000 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

/*
*/

//int d[K];
//vector<int> p;

int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    for(int i = 2; i < K; i++) {
//        if(d[i] == 0) {
//            p.push_back(i);
//            for(int j = i; j < K; j += i)
//                d[j] = i;
//        }
//    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> res(1, a[0]);
    for(int i = 1; i < n; i++) {
        if(__gcd(a[i], res.back()) > 1) {
            res.push_back(1);
//            for(auto x : p) {
//                if(a[i] % x != 0 && res.back() != 0) {
//                    res.push_back(x);
//                    break;
//                }
//            }
        }

        res.push_back(a[i]);
    }

    cout << res.size() - n << endl;
    for(auto x : res)
        cout << x << ' ';
    cout << endl;
}