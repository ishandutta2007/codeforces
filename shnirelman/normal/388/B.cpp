#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1003;
const int L = 60;

bool g[N][N];

int main() {
    int k;
    cin >> k;



    int cur = 35;
    for(int i = 1; i < 33; i++) {
        for(int l = 0; l < 2; l++, cur++) {
            g[cur][i] = true;
            g[i][cur] = true;
            g[cur][i + 1] = true;
            g[i + 1][cur] = true;
        }
    }

    int b = cur;

    g[0][cur] = g[cur][0] = true;
    cur++;

    for(int l = 0; l < 100; l++, cur++) {
        g[cur - 1][cur] = g[cur][cur - 1] = true;
    }

    for(int i = 0; (1 << i) <= k; i++) {
        if((1 << i) & k) {
            int x = L + b - i * 2;
            g[i + 1][x] = true;
            g[x][i + 1] = true;
        }
    }

    cout << cur << endl;
    for(int i = 0; i < cur; i++) {
        for(int j = 0; j < cur; j++)
            cout << (g[i][j] ? 'Y' : 'N');
        cout << endl;
    }
}