#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

const int inf = 1e9 + 7;
const double ep = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, fi[30];
char s[N];
vector <int> vec;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i ++) fi[s[i]-'a'] ++;
    for (int i = 0; i < 26; i ++)
        if (fi[i] & 1) vec.pb(i);
    int sz = vec.size(), x = -1;
    for (int i = 0; i < sz / 2; i ++) fi[vec[i]] ++, fi[vec[sz-i-1]] --;
    for (int i = 0, j = 0; i < n / 2; i ++) {
        while (fi[j] < 2) j ++;
        s[i] = s[n-1-i] = j + 'a';
        fi[j] -= 2;
    }
    if (n & 1) s[n/2] = vec[sz/2] + 'a';
    puts(s);

    return 0;
}