#include <bits/stdc++.h>
using namespace std;
 
int mat[5500][5500];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, g;
    cin >> n;
    g = n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n / 4; j++) {
            char c = s[j];
            int v;
            if(c >= '0' && c <= '9')
                v = c - '0';
            else
                v = c - 'A' + 10;
            for(int t = 0; t < 4; t++) {
                mat[i][4*j + 3 - t] = ((v & (1 << t)) ? 1 : 0);
            }
        }
    }
    int sz = 1;
    for(int i = 0; i < n; i++) {
        sz = 1;
        for(int j = 0; j < n; j++) {
            if(j == n - 1 || mat[i][j] != mat[i][j + 1]) {
                g = __gcd(g, sz);
                sz = 1;
            }
            else
                sz++;
        }
    }
    for(int j = 0; j < n; j++) {
        sz = 1;
        for(int i = 0; i < n; i++) {
            if(i == n - 1 || mat[i][j] != mat[i + 1][j]) {
                g = __gcd(g, sz);
                sz = 1;
            }
            else
                sz++;
        }
    }
    cout << g << endl;
}