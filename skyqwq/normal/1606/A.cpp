// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 105;

char s[N];
 
int main() {
    int T; read(T);
    while (T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        if (s[1] == s[n]) printf("%s\n", s + 1);
        else {
            int p = 1;
            while (p < n && s[p + 1] == s[1]) p++;
            int q = 1;
            while (q < n && s[n - q] == s[n]) q++;
            if (p < q) {
                for (int i = 1; i <= p; i++) s[1] = s[n];
            } else for (int i = n - q + 1; i <= n; i++) s[n] = s[1];
            printf("%s\n", s + 1);
        }
    }
    return 0;
}