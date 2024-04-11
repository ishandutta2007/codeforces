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
int n; 
int a[N][N];
int b[N];
int c[N]; bool f[N];
int A[N], L;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        for (int j = 0; j < n; j ++) {
            if (s[j] == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i ++) cin >> b[i];
    while (true) {
        bool F = false;
        for (int i = 0; i < n; i ++) 
            if (b[i] == c[i]) {
                f[i] = 1;
                for (int j = 0; j < n; j ++) 
                    c[j] += a[i][j];
                F = true;
            }
        if (!F) break;
    }
    for (int i = 0; i < n; i ++) 
        if (f[i]) {
            A[L++] = i;
        }
    printf ("%d\n", L);
    for (int i = 0; i < L; i ++) 
        printf ("%d%c", A[i]+1, i == L-1?'\n':' ');
    return 0;
}