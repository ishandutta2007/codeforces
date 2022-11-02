#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N;
char s[300005];
ll ans;

int main()
{
    scanf(" %s", s);
    N = strlen(s);
    if ((s[0]-'0') % 4 == 0) ans++;
    for (int i = 1; i < N; i++) {
        if ((s[i]-'0') % 4 == 0) ans++;
        if (((s[i-1]-'0') * 10 + s[i]-'0') % 4 == 0) ans += i;
    }
    printf("%lld\n", ans);
}