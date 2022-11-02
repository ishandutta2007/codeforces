#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200*1000+5;

int N, B;
ll ct, z[MaxN];
std::queue<std::pair<ll,int>> q;

int main() {
    scanf("%d%d", &N, &B);
    for (int i = 0; i < N; i++) {
        ll t, d; scanf("%lld%lld", &t, &d);
        while (!q.empty() && ct + q.front().first <= t) {
            ct += q.front().first;
            z[q.front().second] = ct;
            q.pop();
        }
        if (q.empty()) domax(ct, t);
        if (sz(q) <= B) q.emplace(d, i);
        else z[i] = -1;
    }
    while (!q.empty()) {
        ct += q.front().first;
        z[q.front().second] = ct;
        q.pop();
    }
    for (int i = 0; i < N; i++) printf("%lld%c", z[i], " \n"[i == N-1]);
}