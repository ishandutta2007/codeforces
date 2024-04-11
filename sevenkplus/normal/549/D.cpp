#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110

int n, m;
int a[N][N];
int s[N][N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        for (int j = 0; j < m; j ++) {
            if (s[j] == 'W') a[i][j] = 1;
            else a[i][j] = -1;
        }
    }
    if (a[n-1][m-1] == -1) {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                a[i][j] = -a[i][j];
    }
    int S = 1;
    for (int i = n-1; i >= 0; i --)
        for (int j = m-1; j >= 0; j --) {
            int ss = 0;
            if (i < n-1) ss += s[i+1][j];
            if (j < m-1) ss += s[i][j+1];
            if (i < n-1 && j < m-1) ss -= s[i+1][j+1];
            if (a[i][j]+ss != 1) S ++;
            s[i][j] = 1-a[i][j];
        }
    printf ("%d\n", S);
    return 0;
}