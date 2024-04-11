#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005, MaxQ = 105;

int N, Q, a[MaxN], b[MaxN], ql[MaxQ], qr[MaxQ];
std::vector<std::pair<int, int>> v;
ll ans[MaxQ];

ll f(int a) {
    return ll(a)*(a-1)/2;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &ql[i], &qr[i]);
        ql[i]--;
        qr[i]--;
    }
    
    N--;
    for (int i = 0; i < N; i++) {
        b[i] = std::abs(a[i+1] - a[i]);
        v.push_back(std::make_pair(b[i], i));
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    std::set<int> s;
    s.insert(-1);
    s.insert(N);
    for (auto p : v) {
        int i = p.second;
        auto tmp = s.lower_bound(i);
        tmp--;
        int l = *tmp + 1;
        int r = *s.upper_bound(i);
        //printf("%d %d %d\n", i, l, r);
        for (int q = 0; q < Q; q++) if (ql[q] <= i && i < qr[q]) {
            int qql = std::max(ql[q], l);
            int qqr = std::min(qr[q], r);
            if (qql < qqr) {
                ans[q] += (f(qqr-qql+1) - f(i-qql+1) - f(qqr-i)) * b[i];
                //if (q == 0) printf("hi %d %d\n", qql, qqr);
            }
        }
        s.insert(i);
    }
    
    for (int i = 0; i < Q; i++) printf("%lld\n", ans[i]);
}