#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, a[MaxN], b[MaxN], c[MaxN], ans;
std::pair<int, int> v[MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d", &v[i].first, &v[i].second);
    std::sort(v, v+N);
    for (int i = 0; i < N; i++) {
        std::tie(a[i], b[i]) = v[i];
        int j = std::lower_bound(a, a+i+1, a[i]-b[i]) - a;
        c[i] = j ? c[j-1] + 1 : 1;
        domax(ans, c[i]);
    }
    printf("%d\n", N-ans);
}