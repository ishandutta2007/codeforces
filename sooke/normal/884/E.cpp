#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1 << 16 | 233;

int f[N], a[N];
char c[N];
int n, m, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int merge(int x, int y) {
    int a = find(x), b = find(y);
    if(a != b) ans--, f[a] = b;
}

int main() {
    cin >> n >> m;
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1); int len = 0;
        for(register int j = 1; j <= m / 4; j++) {
            int num; if(c[j] >= '0' && c[j] <= '9') num = c[j] - '0';
            else num = c[j] - 'A' + 10;
            a[++len] = (num >> 3) & 1;
            a[++len] = (num >> 2) & 1;
            a[++len] = (num >> 1) & 1;
            a[++len] = num & 1; 
        }
        for(register int j = 1; j <= m; j++) {
            if(a[j]) ans++, f[j + m] = j + m;
            else f[j + m] = 0;
        }
        for(register int j = 1; j <= m; j++) {
            if(a[j]) {
                if(f[j]) merge(j, j + m);
                if(j > 1 && a[j - 1]) merge(j + m - 1, j + m);
            }
        }
        for(register int j = 1; j <= m; j++) {
            if(a[j]) f[j] = find(j + m) - m;
            else f[j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}