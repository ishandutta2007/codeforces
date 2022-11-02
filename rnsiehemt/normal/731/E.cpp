#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n;
ll a[maxn], dp[maxn], s[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        s[i+1] = s[i] + a[i];
    }
    ll best = s[n];
    for (int i = n-1; i >= 0; i--) {
        dp[i] = best;
        best = std::max(best, s[i] - dp[i]);
    }
    printf("%lld\n", dp[1]);
}