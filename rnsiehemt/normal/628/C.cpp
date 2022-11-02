#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, K;
char s[100005], t[100005];

int main()
{
    scanf("%d%d %s", &N, &K, s);
    int max = 0;
    for (int i = 0; i < N; i++) max += std::max(s[i]-'a', 'z'-s[i]);
    if (max < K) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (s[i]-'a' > 'z'-s[i]) {
            if (K >= s[i]-'a') {
                t[i] = 'a';
                K -= s[i]-'a';
            } else {
                t[i] = s[i] - K;
                K = 0;
            }
        } else {
            if (K >= 'z'-s[i]) {
                t[i] = 'z';
                K -= 'z'-s[i];
            } else {
                t[i] = s[i] + K;
                K = 0;
            }
        }
    }
    t[N] = '\0';
    printf("%s\n", t);
}