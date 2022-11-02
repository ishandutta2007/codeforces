#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, ans = 6;
char t[7];
std::string s[1005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", t);
        s[i] = t;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = 0;
            for (int k = 0; k < 6; k++) if (s[i][k] != s[j][k]) x++;
            domin(ans, (x-1)/2);
        }
    }
    printf("%d\n", ans);
}