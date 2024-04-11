#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n, max;
ll a[maxn];
std::map<ll, int> c;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    for (int i = 0; i < n; i++) {
        domax(max, ++c[a[i]]);
        a[i+1] += a[i];
    }
    printf("%d\n", n - max);
}