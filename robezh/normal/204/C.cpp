#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 50, K = 26;

int ch(char c) {return c - 'A';}

int n;
string A, B;
ll psum[K][N], ssum[K][N];
ld tot = 0, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++) d += ((ld)i * i);
    A = " " + A, B = " " + B;
    for(int i = 1; i <= n; i++) {
        for(char c = 'A'; c <= 'Z'; c++) psum[ch(c)][i] = psum[ch(c)][i-1];
        psum[ch(B[i])][i] += i;
    }
    for(int i = n; i >= 1; i--) {
        for(char c = 'A'; c <= 'Z'; c++) ssum[ch(c)][i] = ssum[ch(c)][i+1];
        ssum[ch(B[i])][i] += n - i + 1;
        tot += (ld)psum[ch(A[i])][i] * (n - i + 1) / d;
        tot += (ld)ssum[ch(A[i])][i+1] * i / d;
    }
    cout << fixed << setprecision(10) << tot << endl;
}