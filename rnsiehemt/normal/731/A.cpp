#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char s[105];
int ans;

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    char p = 'a';
    for (int i = 0; i < n; i++) {
        int k = (26 + s[i] - p) % 26;
        ans += std::min(k, (26-k)%26);
        p = s[i];
    }
    printf("%d\n", ans);
}