#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define x first
#define y second

template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll linf = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-7;

#define N 105

int n;
char t[N];
char s[N][4];
bool l[N], r[N];
int main() {
    scanf("%s", t);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s", s[i]);
        if (!strcmp(s[i], t)) return puts("YES"), 0;
        l[s[i][0]-'a'] = 1;
        r[s[i][1]-'a'] = 1;
    }
    if (l[t[1]-'a'] && r[t[0]-'a']) return puts("YES"), 0;
    puts("NO");
    return 0;
}