#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 300*1000+5;

int n;
char s[maxn], t[maxn], ans[maxn];

int main() {
    scanf(" %s %s", s, t);
    n = strlen(s);

    std::sort(s, s+n);
    std::sort(t, t+n);
    int i = 0, j = n-1;
    int k = 0;
    int turn = 0;
    while (k < n) {
        if (turn == 0) {
            if (s[i] < t[j]) {
                ans[k++] = s[i++];
            } else {
                break;
            }
            turn = 1-turn;
        } else {
            if (s[i] < t[j]) {
                ans[k++] = t[j--];
            } else {
                break;
            }
            turn = 1-turn;
        }
    }
    int left = n - k;
    int b = left / 2, a = left - b;
    if (turn == 1) std::swap(a, b);
    i += a - 1;
    j -= b - 1;
    int kk = n-1;
    while (kk >= k) {
        if (turn == 0) {
            ans[kk--] = s[i--];
        } else {
            ans[kk--] = t[j++];
        }
        turn = 1 - turn;
    }
    printf("%s\n", ans);
}