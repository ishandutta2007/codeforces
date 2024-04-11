#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, k, a, b;
char ch[5] = "GBG";

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d %d %d", &n, &k, &a, &b);
    int i = 0;
    if (a < b) swap(a, b), i ++;
    b ++;
    if (a > 1ll * b * k) puts("NO");
    else {
        int t = a / b, r = a - t * b;
        for (int j = 0; j < b; j ++) {
            for (int k = 0; k < t; k ++) pc(ch[i]);
            if (j < r) pc(ch[i]);
            if (j < b - 1) pc(ch[i+1]);
        }
        puts("");
    }

    return 0;
}