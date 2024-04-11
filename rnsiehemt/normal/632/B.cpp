#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 500*1000+5;

int N;
ll s[MaxN], x, y, z;
char t[MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &s[i]);
    scanf(" %s", t);
    for (int i = 0; i < N; i++) {
        if (t[i] == 'A') {
            y += s[i];
        } else {
            x += s[i];
            y -= s[i];
        }
        domax(z, y);
    }
    y = 0;
    for (int i = N-1; i >= 0; i--) {
        if (t[i] == 'A') {
            y += s[i];
        } else {
            y -= s[i];
        }
        domax(z, y);
    }
    printf("%lld\n", x+z);
}