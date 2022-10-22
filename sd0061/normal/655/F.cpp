#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000005;
const int Q = 1e9 + 7;
int mu[N] , inv[N] , C[N] , W[N] , D[N] , s[N];
int n , K , q;
vector<int> fac[N];

inline void add(int &A , int B) {
    if (B < 0)
        B += Q;
    A += B;
    if (A >= Q)
        A -= Q;
}

int main() {
    scanf("%d%d%d" , &n , &K , &q);
    inv[1] = 1;
    for (int i = 2 ; i < N ; ++ i)
        inv[i] = (LL)(Q - Q / i) * inv[Q % i] % Q;
    mu[1] = 1;
    for (int i = 1 ; i < N ; ++ i) {
        for (int j = i + i ; j < N ; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int i = 1 ; i < N ; ++ i) {
        //if (mu[i] == 0) continue;
        for (int j = i ; j < N ; j += i) {
            // fac[j].push_back(i);
            add(s[j] , i * mu[j / i]);
        }
    }
    for (int i = 1 ; i < N ; ++ i) {
        if (s[i] == 0) continue;
        for (int j = i ; j < N ; j += i) {
            fac[j].push_back(i);
        }
    }
    int res = 0;
    for (int i = 0 ; i < n + q ; ++ i) {
        int x;
        scanf("%d" , &x);
        for (auto &y : fac[x]) {
            int tmp = C[y];
            ++ D[y];
            if (D[y] == K) {
                C[y] = 1;
            } else if (D[y] > K) {
                C[y] = (LL)C[y] * D[y] % Q * inv[D[y] - K] % Q;
            }
            int delta = (C[y] - tmp + Q) % Q;
            add(res , (LL)delta * s[y] % Q);
        }
        if (i >= n)
            printf("%d\n" , res);
    }



    return 0;
}