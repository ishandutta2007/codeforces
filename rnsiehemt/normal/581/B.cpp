#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

int N, h[100005], ans[100005];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &h[i]);
    int max = 0;
    for (int i = N-1; i >= 0; i--) {
        ans[i] = std::max(0, max+1 - h[i]);
        domax(max, h[i]);
    }
    for (int i = 0; i < N; i++) printf("%d%c", ans[i], " \n"[i == N-1]);
}