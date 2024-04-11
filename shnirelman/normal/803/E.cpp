//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

bool dp[N][N * 2];
int p[N][N * 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    dp[0][N] = true;

//    cout << dp[0][N] << endl;

    for(int i = 0; i < n; i++) {
        for(int j = N - k + 1; j < N + k; j++) {
//            cout << i << ' ' << j - N << endl;
            if(dp[i][j]) {
//                cout << "for " << i << ' ' << j - N << endl;
                if(s[i] == 'W') {
                    dp[i + 1][j + 1] = true;
                    p[i + 1][j + 1] = j;
//                    cout << "-> " << i + 1 << ' ' << j + 1 - N  << endl;
                } else if(s[i] == 'L') {
                    dp[i + 1][j - 1] = true;
                    p[i + 1][j - 1] = j;//cout << "-> " << i + 1 << ' ' << j - 1 - N  << endl;
                } else if(s[i] == 'D') {
                    dp[i + 1][j] = true;
                    p[i + 1][j] = j;//cout << "-> " << i + 1 << ' ' << j - N << endl;
                } else {
                    dp[i + 1][j + 1] = true;
                    p[i + 1][j + 1] = j;
                    dp[i + 1][j - 1] = true;
                    p[i + 1][j - 1] = j;
                    dp[i + 1][j] = true;
                    p[i + 1][j] = j;
                }
            }
        }

    }

    int j = -1;
    if(dp[n][N + k]) {
        j = N + k;
    } else if(dp[n][N - k]) {
        j = N - k;
    } else {
        cout << "NO" << endl;
        return 0;
    }

    int i = n;

    while(i > 0) {
        if(p[i][j] < j)
            s[i - 1] = 'W';
        else if(p[i][j] > j)
            s[i - 1] = 'L';
        else
            s[i - 1] = 'D';

        j = p[i][j];
        i--;
    }

    cout << s << endl;

}