#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, m[400], f[400], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char c; int l, r;
        scanf(" %c%d%d", &c, &l, &r);
        for (int j = l; j <= r; j++) (c == 'F' ? f : m)[j]++;
    }
    for (int i = 0; i < 400; i++) {
        domax(ans, std::min(m[i], f[i])*2);
    }
    printf("%d\n", ans);
}