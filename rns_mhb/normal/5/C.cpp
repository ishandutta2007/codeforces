//7
#include <bits/stdc++.h>
using namespace std;
#define N 1000100
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int fig, cur, ans, len[N], plc[N];
char s[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') plc[++cur] = i;
        else if (cur) {
            len[i] = len[plc[cur]-1] + i - plc[cur] + 1, cur --;
            if (ans < len[i]) ans = len[i], fig = 1;
            else if (ans == len[i]) fig ++;
        }
    }
    if (!ans) fig = 1;
    printf("%d %d\n", ans, fig);

    return 0;
}