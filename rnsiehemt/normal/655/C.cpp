#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100*1000+5;

int N, K, ans = 1e9;
char s[MaxN];
std::deque<int> v;

int get(int i) {
    return std::max(i - v.front(), v.back() - i);
}
int dist() {
    int l = 0, h = sz(v), k = (v.back()+v.front()+1)/2;
    while (h-l > 1) {
        int m = (l+h)/2;
        if (v[m] < k) l = m;
        else h = m;
    }
    return std::min(get(v[l]), get(v[l+1]));
}

int main() {
    scanf("%d%d %s", &N, &K, s);
    int i;
    for (i = 0; sz(v) < K+1; i++) {
        if (s[i] == '0') v.pb(i);
    }
    domin(ans, dist());
    for (; i < N; i++) {
        if (s[i] == '0') {
            v.pb(i);
            v.pop_front();
        }
        domin(ans, dist());
    }
    printf("%d\n", ans);
}