#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool look(T &a, T b = true) { return (a == b ? true : (a = b, false)); }
typedef long long ll;

const int MaxN = 100005;

int N, k[MaxN], blocks;
std::pair<int, int> a[MaxN], b[MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        b[i] = a[i];
    }
    std::sort(b, b+N);
    for (int i = 0; i < N; i++) {
        int j = std::lower_bound(b, b+N, a[i]) - b;
        if (j >= i) domax(k[i], j);
        else domax(k[j], i);
    }
    int j = 0;
    for (int i = 0; i < N; i++) {
        domax(j, k[i]);
        assert(j >= i);
        if (j == i) blocks++;
    }
    printf("%d\n", blocks);
}