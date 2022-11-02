#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N;
std::vector<int> a;

int main() {
    scanf("%d", &N);
    a.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    std::sort(all(a));
    a.erase(std::unique(all(a)), a.end());
    for (int i = 0; i+2 < sz(a); i++) {
        if (a[i+1] == a[i] + 1 && a[i+2] == a[i] + 2) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}