#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200*1000+5;

int N, x[MaxN], y[MaxN];
std::map<int, ll> a, b;
std::set<int> c, d;
std::map<std::pair<int,int>, ll> s;
ll ans;

ll f(ll a) {
    return a*(a-1)/2;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &x[i], &y[i]);
        ans -= s[{x[i],y[i]}];
        s[{x[i],y[i]}]++;
        a[x[i]]++;
        b[y[i]]++;
        c.insert(x[i]);
        d.insert(y[i]);
    }
    for (int i : c) ans += f(a[i]);
    for (int i : d) ans += f(b[i]);
    printf("%lld\n", ans);
}