//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 100;
const int K = 400;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 8;

    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(char c : s) {
            if(c == 'Q')
                s1 += 9;
            else if(c == 'R')
                s1 += 5;
            else if(c == 'N' || c == 'B')
                s1 += 3;
            else if(c == 'P')
                s1 += 1;
            else if(c == 'q')
                s2 += 9;
            else if(c == 'r')
                s2 += 5;
            else if(c == 'n' || c == 'b')
                s2 += 3;
            else if(c == 'p')
                s2 += 1;
        }
    }

    cout << (s1 > s2 ? "White" : (s1 < s2 ? "Black" : "Draw")) << endl;
}