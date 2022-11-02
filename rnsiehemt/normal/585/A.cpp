#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 4005;

int N, ans; ll v[MaxN], d[MaxN], p[MaxN];
bool done[MaxN];
std::vector<int> w;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld%lld%lld", &v[i], &d[i], &p[i]);
    for (int i = 0; i < N; i++) {
        if (p[i] < 0) continue;
        ans++; w.push_back(i);
        for (int j = i+1; j < N; j++) {
            if (v[i] < 0 || p[j] < 0) continue;
            p[j] -= v[i];
            v[i]--;
        }
        for (int j = i+1; j < N; j++) {
            if (p[j] < 0) {
                if (done[j]) continue;
                done[j] = true;
                for (int k = j+1; k < N; k++) {
                    p[k] -= d[j];
                }
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < sz(w); i++) printf("%d%c", w[i]+1, " \n"[i == sz(w)-1]);
}