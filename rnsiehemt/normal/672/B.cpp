#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n, k;
char s[maxn];
bool seen[256];

int main() {
    scanf("%d %s", &n, s);
    if (n > 26) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (seen[s[i]]) k++;
        seen[s[i]] = true;
    }
    printf("%d\n", k);
}