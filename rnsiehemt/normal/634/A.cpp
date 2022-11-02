#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005;

int N, a[MaxN], b[MaxN];
std::vector<int> aa, bb;

void go(int *c, std::vector<int> &cc) {
    int start = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
        if (c[i] == 1) start = i;
    }
    for (int i = start; i < start+N; i++) {
        int j = i % N;
        if (c[j]) cc.pb(c[j]);
    }
}

int main()
{
    scanf("%d", &N);
    go(a, aa);
    go(b, bb);
    printf("%s\n", (aa == bb ? "YES" : "NO"));
}