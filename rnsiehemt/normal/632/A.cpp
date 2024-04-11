#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N;
ll P, C, n;
std::vector<bool> t;
char s[9];

int main()
{
    scanf("%d%lld", &N, &P);
    for (int i = 0; i < N; i++) {
        scanf(" %s", s);
        t.pb(strlen(s) == 8);
    }
    std::reverse(all(t));
    for (bool b : t) {
        if (b) {
            C += (2*n+1)*P/2;
            n = 2*n+1;
        } else {
            C += n*P;
            n *= 2;
        }
    }
    printf("%lld\n", C);
}