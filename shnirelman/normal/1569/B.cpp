//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<char>> res(n, vector<char>(n, '.'));
    for(int i = 0; i < n; i++)
        res[i][i] = 'X';

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            for(int j = 0; j < n; j++) {
                if(res[i][j] == '.') {
                    res[i][j] = res[j][i] = '=';
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '2') {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                cnt += (res[i][j] == '+');
            for(int j = 0; j < n; j++) {
                if(res[i][j] == '.') {
                    if(cnt == 0) {
                        res[i][j] = '+';
                        res[j][i] = '-';
                        cnt++;
                    } else {
                        res[i][j] = '-';
                        res[j][i] = '+';
                    }
                }
            }

            if(cnt == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }


    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << res[i][j];
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}