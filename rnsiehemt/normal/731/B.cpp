#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a[200*1000+5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < n; i++) {
        if (a[i]&1) {
            if (i == n-1 || a[i+1] == 0) {
                printf("NO\n");
                return 0;
            }
            a[i+1]--;
        }
    }
    printf("YES\n");
}