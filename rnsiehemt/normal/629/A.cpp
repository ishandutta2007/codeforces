#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, ans;
char s[105][105];

int f(int i) {
    return i*(i-1)/2;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf(" %s", s[i]);
    for (int y = 0; y < N; y++) {
        int c = 0, d = 0;
        for (int x = 0; x < N; x++) {
            if (s[y][x] - '.') c++;
            if (s[x][y] - '.') d++;
        }
        ans += f(c) + f(d);
    }
    printf("%d\n", ans);
}